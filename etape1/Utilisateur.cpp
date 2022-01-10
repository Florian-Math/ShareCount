#include "Utilisateur.h"
#include "DatabaseManager.h"

Utilisateur::Utilisateur(const QString& email, const QString& nom, const QString& prenom, const QString& mdp){
    this->registered = false;
    this->email = email;
    this->nom = nom;
    this->prenom = prenom;
    this->mdp = mdp;
}

bool Utilisateur::save(){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    query.prepare("SELECT email FROM utilisateur WHERE email = :email");
    query.bindValue(":email", email);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    // si l'utilisateur n'existe pas
    if(!query.first()){
        query.prepare("INSERT INTO utilisateur(email, nom, prenom, mdp) VALUES(:email, :nom, :prenom, :mdp)");
        query.bindValue(":email", email);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":mdp", mdp);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();
        this->registered = true;

        return true;
    }else
        return false;
}

Utilisateur* Utilisateur::connexion(const QString email, const QString mdp){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    query.prepare("SELECT email, nom, prenom, mdp FROM utilisateur WHERE email = :email AND mdp = :mdp");
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    // si l'utilisateur existe
    if(query.first()){
        Utilisateur* u = new Utilisateur(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString());
        u->registered = true;
        return u;
    }else
        return nullptr;
}

QString Utilisateur::getEmail() const { return email; }
QString Utilisateur::getNom() const { return nom; }
QString Utilisateur::getPrenom() const { return prenom; }
