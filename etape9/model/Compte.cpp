#include "Compte.h"

#include "Utilisateur.h"


Compte::~Compte(){
    qDebug() << "DELETE Compte :" << this;

};

Compte::Compte()
    : GroupePayement(){}

Compte::Compte(const QString& titre, const QString& description)
    : GroupePayement(titre, description)
{
}

Compte::Compte(const int& id, const QString& titre, const QString& description)
    : GroupePayement(id, titre, description)
{
}

bool Compte::save(){
    if(this->estVide()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // si le compte est deja dans la base
    if(this->id != -1){
        // modif compte
        query.prepare("UPDATE Compte SET titre = :titre, description = :description WHERE id = :id");
        query.bindValue(":id", id);
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        // modif depenses
        for (int i = 0; i < depenses.size(); i++) {
            if (!depenses[i].save(id)) return false; // n'arrive jamais
        }
        return true;

    }else{
        // ajout compte
        query.prepare("INSERT INTO Compte(titre, description) VALUES(:titre, :description)");
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        this->id = query.lastInsertId().toInt();

        for(int i = 0; i < participants.size(); i++){
            Utilisateur u = participants[i];

            query.prepare("INSERT INTO ParticipantsCompte(id, email) VALUES(:id, :email)");
            query.bindValue(":id", this->id);
            query.bindValue(":email", u.getEmail());

            if(!query.exec()) qWarning() << "Error: " << db.lastError();
        }

        return true;
    }
}

Compte* Compte::getCompte(const int id){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // vérification compte existant
    query.prepare("SELECT id, titre, description FROM Compte WHERE id = :id");
    query.bindValue(":id", id);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    if(!query.first()) return nullptr; // si il n'existe pas retourne null

    // construit le compte
    Compte* compte = new Compte(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString());

    // lie les utilisateurs au compte
    query.prepare("SELECT id, email FROM ParticipantsCompte WHERE id = :id");
    query.bindValue(":id", id);

    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    while (query.next()) {
        Utilisateur u = Utilisateur::getUtilisateur(query.value(1).toString());
        if(!u.estVide()) compte->participants.append(u);
    }

    // ajoute les depenses au compte
    compte->depenses = Depense::getDepensesOfCompte(id, compte);

    compte->updateBalances();
    compte->updateEquilibrage();

    return compte;
}

bool Compte::ajouterParticipant(const Utilisateur& u){
    bool res = GroupePayement::ajouterParticipant(u);

    updateBalances();
    updateEquilibrage();
    return res;
}

bool Compte::ajouterDepense(const Depense& d){
    depenses.append(d);

    updateBalances();
    updateEquilibrage();
    return true;
}

void Compte::updateBalances(){
    // set balances a 0
    for (int i = 0; i < participants.size(); i++) {
        balances[participants[i].getEmail()] = 0;
    }

    // update balances
    for(int i = 0; i < depenses.size(); i++){
        Depense& d = depenses[i];
        int participantsDepSize = (d.getParticipants().size() > 0 ? d.getParticipants().size() : participants.size()); // si participants = 0 => participants = all

        for(int j = 0; j < participants.size(); j++){
            Utilisateur& p = participants[j];

            // si l'utilisateur a payé la depense
            if(p.getEmail() == d.getPayeur().getEmail())
                balances[p.getEmail()] += d.getMontant();

            // si l'utilisateur est conserné par la depense
            if(d.getParticipants().isEmpty() || d.getParticipants().contains(p.getEmail()))
                balances[p.getEmail()] -= d.getMontant() / participantsDepSize;
        }
    }
/*
    for (int i = 0; i < balances.keys().size(); i++){
        QString k = balances.keys().at(i);

        qDebug() << k << balances[k];
    }*/
}

void Compte::updateEquilibrage(){
    equilibrages.clear();

    QHash<QString, float> hash = balances; // copie balance
    QList<QString> pos;
    QList<QString> neg;

    for (int i = 0; i < hash.keys().size(); i++){
        QString k = hash.keys().at(i);

        if(hash[k] > 0) pos.append(k);
        else if(hash[k] < 0) neg.append(k);
    }

    for(int i = 0; i < neg.size(); i++){
        QString& negEmail = neg[i];
        float negVal = hash[negEmail];

        int j = 0;
        while (negVal < 0) {
            //if(j >= pos.size()) break;

            QString posEmail = pos[j];
            float posVal = hash[posEmail];

            // si il en reste
            if(posVal + negVal >= 0) {
                // crée depense max
                Depense d("Equilibrage", "", -negVal, this);
                d.setPayeur(negEmail);
                d.ajouterParticipant(posEmail);

                equilibrages.append(d);

                hash[negEmail] = 0;
                hash[posEmail] += negVal;

                negVal = 0;
            }else if(posVal != 0){
                // crée depense pile
                Depense d("Equilibrage", "", posVal, this);
                d.setPayeur(negEmail);
                d.ajouterParticipant(posEmail);

                equilibrages.append(d);

                negVal += posVal;
                j++;
            }
        }
    }

/*
    qDebug() << "EQUILIBRAGE : ";
    for (int i = 0; i < equilibrages.size(); i++){
        qDebug() << equilibrages[i].getPayeur().getEmail() + " -> " << equilibrages[i].getParticipants()[0] << " : " << equilibrages[i].getMontant() << "EUR";
    }*/
}

float Compte::getBalance(const QString& email){
    return balances[email];
}

Utilisateur* Compte::getParticipant(const QString& email){
    for (int i = 0; i < participants.size(); i++) {
        if(participants.at(i).getEmail() == email) return &participants[i];
    }
    return nullptr;
}

Depense& Compte::getEquilibrage(int i){
    return equilibrages[i];
}

int Compte::getEquilibragesSize(){
    return equilibrages.size();
}


Depense& Compte::getDepense(int i){
    return depenses[i];
}

int Compte::getDepensesSize(){
    return depenses.size();
}

QString Compte::getType() const{
    return "Compte";
}
