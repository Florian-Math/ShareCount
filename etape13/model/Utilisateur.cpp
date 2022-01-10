#include "Utilisateur.h"

#include "GroupePayement.h"
#include "Compte.h"
#include "Cagnotte.h"

Utilisateur::Utilisateur(const QString& email, const QString& nom, const QString& prenom, const QString& mdp) {
    this->registered = false;
    this->email = email;
    this->nom = nom;
    this->prenom = prenom;
    this->mdp = mdp;
}

Utilisateur::Utilisateur(const QString& email, const QString& nom, const QString& prenom) {
    this->registered = false;
    this->email = email;
    this->nom = nom;
    this->prenom = prenom;
}

Utilisateur::Utilisateur() {};

Utilisateur::~Utilisateur() {
    qDebug() << "DELETE Utilisateur :" << this;
};

bool Utilisateur::save(){
    if(this->estVide()) return false;
    if(this->mdp.isEmpty()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // recup l'utilisateur dans la base
    query.prepare("SELECT email FROM utilisateur WHERE email = :email");
    query.bindValue(":email", email);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    // si l'utilisateur n'existe pas
    if(!query.first()){

        // insert l'utilisateur
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

Utilisateur Utilisateur::connexion(const QString& email, const QString& mdp){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // recup l'utilisateur via email et mdp
    query.prepare("SELECT email, nom, prenom, mdp FROM utilisateur WHERE email = :email AND mdp = :mdp");
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    // si l'utilisateur existe
    if(query.first()){
        // construit l'utilisateur
        Utilisateur u(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString());
        u.registered = true;

        // relie les comptes à l'utilisateur
        query.prepare("SELECT id FROM ParticipantsCompte WHERE email = :email");
        query.bindValue(":email", email);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        while (query.next()) {
            Compte* c = Compte::getCompte(query.value(0).toInt());
            u.comptes.append(c);
        }

        // relie les cagnottes à l'utilisateur
        query.prepare("SELECT id FROM ParticipantsCagnotte WHERE email = :email");
        query.bindValue(":email", email);
        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        while (query.next()) {
            Cagnotte* c = Cagnotte::getCagnotte(query.value(0).toInt());
            u.cagnottes.append(c);
        }

        return u;
    }else
        return Utilisateur();
}

Utilisateur Utilisateur::getUtilisateur(const QString &email){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    query.prepare("SELECT email, nom, prenom FROM utilisateur WHERE email = :email");
    query.bindValue(":email", email);
    if(!query.exec()) qWarning() << "Error: " << db.lastError();

    // si l'utilisateur existe
    if(query.first())
        return Utilisateur(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), "");
    else
        return Utilisateur();
}

void Utilisateur::ajouterCompte(Compte* c){
    comptes.append(c);
}

void Utilisateur::ajouterCagnotte(Cagnotte* c){
    cagnottes.append(c);
}

void Utilisateur::supprimerGroupe(GroupePayement* groupe){
    if(groupe->getType() == "Compte"){
        for(int i = 0; i < comptes.size(); i++){
            if(comptes.at(i) == groupe){
                comptes.removeAt(i);
                return;
            }
        }
    }
    else if(groupe->getType() == "Cagnotte"){
        for(int i = 0; i < cagnottes.size(); i++){
            if(cagnottes.at(i) == groupe){
                cagnottes.removeAt(i);
                return;
            }
        }
    }


}

QString Utilisateur::getEmail() const { return email; }
QString Utilisateur::getNom() const { return nom; }
QString Utilisateur::getPrenom() const { return prenom; }

int Utilisateur::getGroupeSize(){
    return comptes.size() + cagnottes.size();
}

int Utilisateur::getCompteSize(){
    return comptes.size();
}

GroupePayement* Utilisateur::getGroupe(int i){
    if(i < comptes.size()) return comptes[i];
    else return cagnottes[i-comptes.size()];
}

bool Utilisateur::estVide() const {
    return email.isEmpty();
}

void Utilisateur::dispose() {
    qDeleteAll(comptes);
    qDeleteAll(cagnottes);
}
