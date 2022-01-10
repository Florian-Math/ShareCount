#include "Compte.h"

Compte::Compte(){}

Compte::Compte(const QString& titre, const QString& description)
{
    this->id = -1;
    this->titre = titre;
    this->description = description;
    this->participants = {};
}

Compte::Compte(const int id, const QString& titre, const QString& description)
{
    this->id = id;
    this->titre = titre;
    this->description = description;
    this->participants = {};
}

bool Compte::save(){
    if(this->estVide()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // ajout compte
    query.prepare("INSERT INTO Compte(titre, description) VALUES(:titre, :description)");
    query.bindValue(":titre", titre);
    query.bindValue(":description", description);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    this->id = query.lastInsertId().toInt();

    for(int i = 0; i < participants.size(); i++){
        Utilisateur u = participants.at(i);

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
    this->registered = true;

    return true;
}

void Compte::ajouterParticipant(Utilisateur u){
    participants.append(u);
}

Compte Compte::getCompte(const int id){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // vérification compte existant
    query.prepare("SELECT id, titre, description FROM Compte WHERE id = :id");
    query.bindValue(":id", id);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    if(!query.first()) return Compte(); // si il n'existe pas retourne compte inexistant

    // construit le compte
    Compte compte(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString());

    // lie les utilisateurs au compte
    query.prepare("SELECT id, email FROM ParticipantsCompte WHERE id = :id");
    query.bindValue(":id", id);

    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    while (query.next()) {
        Utilisateur u = Utilisateur::getUtilisateur(query.value(1).toString());
        if(!u.estVide()) compte.participants.append(u);
    }

    return compte;
}

QString Compte::getTitre() const {
    return titre;
}

QString Compte::getDescription() const {
    return description;
}

QList<Utilisateur>* Compte::getParticipants(){
    return &participants;
}

bool Compte::estVide() const {
    return titre.isEmpty();
}

