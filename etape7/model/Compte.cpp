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

        // TODO: modif utilisateurs

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

            query.prepare("SELECT id from ParticipantsCompte WHERE id = :id AND email = :email");
            if(!query.exec()) qWarning() << "Error: " << db.lastError();

            // si l'utilisateur n'est pas lié au compte
            if(!query.first()){
                query.prepare("INSERT INTO ParticipantsCompte(id, email) VALUES(:id, :email)");
                query.bindValue(":id", this->id);
                query.bindValue(":email", u.getEmail());

                if(!query.exec()) qWarning() << "Error: " << db.lastError();
            }
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
        if(!u.estVide()) compte->ajouterParticipant(u);
    }

    // ajoute les depenses au compte
    compte->depenses = Depense::getDepensesOfCompte(id, compte);

    return compte;
}

bool Compte::ajouterDepense(const Depense& d){
    depenses.append(d);
    return true;
}

Utilisateur* Compte::getParticipant(const QString& email){
    for (int i = 0; i < participants.size(); i++) {
        if(participants.at(i).getEmail() == email) return &participants[i];
    }
    return nullptr;
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
