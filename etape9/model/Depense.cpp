#include "Depense.h"
#include "Compte.h"
#include "Utilisateur.h"
#include <QJsonArray>
#include <QJsonDocument>

Depense::Depense(const int& id, const QString& titre, const QString &date, const float& montant, Compte* compte)
{
    this->id = id;
    this->titre = titre;
    this->date = date;
    this->montant = montant;
    this->compte = compte;
}

Depense::Depense(const QString& titre, const QString& date, const float& montant, Compte* compte){
    this->id = -1;
    this->titre = titre;
    this->date = date;
    this->montant = montant;
    this->compte = compte;
}

Depense::~Depense(){
    qDebug() << "DELETE Depense :" << this;
}

bool Depense::save(int idCompte){
    if(estVide()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // si il n'est pas dans la base
    if(id == -1){
        // insert
        query.prepare("INSERT INTO Depense(titre, date, montant, idCompte, emailPayeur, emailParticipants) VALUES(:titre, :date, :montant, :idCompte, :emailPayeur, :emailParticipants)");
        query.bindValue(":titre", titre);
        query.bindValue(":date", date);
        query.bindValue(":montant", montant);
        query.bindValue(":idCompte", idCompte);
        query.bindValue(":emailPayeur", payeur);

        QJsonArray participantsJSON;
        for (int i = 0; i < participants.size(); i++) {
            participantsJSON.append(participants[i]);
        }
        QJsonDocument doc;
        doc.setArray(participantsJSON);

        query.bindValue(":emailParticipants", doc.toJson());

        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        this->id = query.lastInsertId().toInt();

        return true;
    }else{
        // TODO: modif
        return true;
    }
}


QList<Depense> Depense::getDepensesOfCompte(int id, Compte* compte){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;
    QList<Depense> list;

    query.prepare("SELECT id, titre, date, montant, emailPayeur, emailParticipants FROM Depense WHERE idCompte = :id");
    query.bindValue(":id", id);

    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    while (query.next()) {
        Depense d(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toFloat(), compte);
        d.compte = compte;
        d.payeur = query.value(4).toString();

        // set participants depense
        QJsonDocument doc = QJsonDocument::fromJson(query.value(5).toByteArray());
        QJsonArray arr = doc.array();
        foreach(const QJsonValue& value, arr){
            d.participants.append(value.toString());
        }

        if(!d.estVide()) list.append(d);
    }

    return list;
}

bool Depense::ajouterParticipant(const QString& email) {
    if(compte->getParticipant(email) == nullptr) return false; // si n'est pas enregistré dans le compte retourne false

    for (int i = 0; i < participants.size(); i++) { // si déjà présent retourne false
        if(participants[i] == email) return false;
    }

    participants.append(email);
    return true;
}

QList<QString> Depense::getParticipants() {
    return participants;
}

Utilisateur& Depense::getPayeur(){
    return *compte->getParticipant(payeur);
}

void Depense::setPayeur(const Utilisateur& u){
    payeur = u.getEmail();
}

void Depense::setPayeur(const QString& email){
    payeur = email;
}

void Depense::setCompte(Compte* compte){
    this->compte = compte;
}

QString Depense::getTitre() const{
    return titre;
}

QString Depense::getDate() const{
    return date;
}

float Depense::getMontant() const{
    return montant;
}

bool Depense::estVide() const{
    return titre.isEmpty();
}
