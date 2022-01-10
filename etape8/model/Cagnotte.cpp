#include "Cagnotte.h"

#include "Utilisateur.h"

Cagnotte::~Cagnotte(){
    qDebug() << "DELETE Cagnotte :" << this;
};

Cagnotte::Cagnotte()
    : GroupePayement(){};

Cagnotte::Cagnotte(const QString& titre, const QString& description)
    : GroupePayement(titre, description)
{
}

Cagnotte::Cagnotte(const int& id, const QString& titre, const QString& description)
    : GroupePayement(id, titre, description)
{
}



bool Cagnotte::save(){
    if(this->estVide()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    if(this->id != -1){
        // modif cagnotte
        query.prepare("UPDATE Cagnotte SET titre = :titre, description = :description WHERE id = :id");
        query.bindValue(":id", id);
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        return true;

    }else{
        // ajout cagnotte
        query.prepare("INSERT INTO Cagnotte(titre, description) VALUES(:titre, :description)");
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        this->id = query.lastInsertId().toInt();

        for(int i = 0; i < participants.size(); i++){
            Utilisateur u = participants[i];

            query.prepare("INSERT INTO ParticipantsCagnotte(id, email) VALUES(:id, :email)");
            query.bindValue(":id", this->id);
            query.bindValue(":email", u.getEmail());

            if(!query.exec()) qWarning() << "Error: " << db.lastError();
        }

        return true;
    }

    return true;
}

Cagnotte* Cagnotte::getCagnotte(const int& id){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // vérification compte existant
    query.prepare("SELECT id, titre, description FROM Cagnotte WHERE id = :id");
    query.bindValue(":id", id);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    if(!query.first()) return nullptr; // si il n'existe pas retourne null

    // construit la cagnotte
    Cagnotte* cagnotte = new Cagnotte(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString());

    // lie les utilisateurs a la cagnotte
    query.prepare("SELECT id, email FROM ParticipantsCagnotte WHERE id = :id");
    query.bindValue(":id", id);

    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    while (query.next()) {
        Utilisateur u = Utilisateur::getUtilisateur(query.value(1).toString());
        if(!u.estVide()) cagnotte->participants.append(u);
    }

    return cagnotte;
}

QString Cagnotte::getType() const{
    return "Cagnotte";
}


