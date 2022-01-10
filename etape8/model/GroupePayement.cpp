#include "GroupePayement.h"

#include "Utilisateur.h"

GroupePayement::GroupePayement(){}

GroupePayement::GroupePayement(const QString& titre, const QString& description)
{
    this->id = -1;
    this->titre = titre;
    this->description = description;
    this->participants = {};
}

GroupePayement::GroupePayement(const int& id, const QString& titre, const QString& description)
{
    this->id = id;
    this->titre = titre;
    this->description = description;
    this->participants = {};
}

GroupePayement::~GroupePayement(){
}

bool GroupePayement::ajouterParticipant(const Utilisateur& u){
    if(u.estVide() || this->id == -1) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    query.prepare("SELECT id from Participants" + this->getType() + " WHERE id = :id AND email = :email");
    query.bindValue(":id", this->id);
    query.bindValue(":email", u.getEmail());
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    // si l'utilisateur n'est pas lié au compte
    if(!query.first()){
        query.prepare("INSERT INTO Participants" + this->getType() + "(id, email) VALUES(:id, :email)");
        query.bindValue(":id", this->id);
        query.bindValue(":email", u.getEmail());

        if(!query.exec()) qWarning() << "Error: " << db.lastError();
    }

    // si l'utilisateur est déjà dans le groupe retourne false
    for (int i = 0; i < participants.size(); i++) {
        if(participants[i].getEmail() == u.getEmail()) return false;
    }

    participants.append(u);
    return true;
}

QString GroupePayement::getTitre() const {
    return titre;
}

QString GroupePayement::getDescription() const {
    return description;
}

QList<Utilisateur>& GroupePayement::getParticipants(){
    return participants;
}

Utilisateur& GroupePayement::getParticipant(int i){
    return participants[i];
}

bool GroupePayement::estVide() const {
    return titre.isEmpty();
}

