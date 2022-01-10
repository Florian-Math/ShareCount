#include "Transfert.h"
#include "Cagnotte.h"
#include "Utilisateur.h"

#include <QJsonArray>
#include <QJsonDocument>

Transfert::Transfert(const int& id, const QString& titre, const QString& date, const float& montant, const QString& createur, Cagnotte* cagnotte){
    this->id = id;
    this->titre = titre;
    this->date = date;
    this->montant = montant;
    this->createur = createur;
    this->cagnotte = cagnotte;
}

Transfert::Transfert(const QString& titre, const QString& date, const float& montant, const QString& createur, Cagnotte* cagnotte){
    this->id = -1;
    this->titre = titre;
    this->date = date;
    this->montant = montant;
    this->createur = createur;
    this->cagnotte = cagnotte;
}

Transfert::~Transfert(){
    qDebug() << "DELETE Transfert :" << this;
}

bool Transfert::save(int idCagnotte){
    if(estVide()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // si il n'est pas dans la base
    if(id == -1){
        // insert
        query.prepare("INSERT INTO Transfert(titre, date, montant, idCagnotte, emailCreateur, emailValideurs) VALUES(:titre, :date, :montant, :idCagnotte, :emailCreateur, :emailValideurs)");
        query.bindValue(":titre", titre);
        query.bindValue(":date", date);
        query.bindValue(":montant", montant);
        query.bindValue(":idCagnotte", idCagnotte);
        query.bindValue(":emailCreateur", createur);

        QJsonArray valideursJSON;
        for (int i = 0; i < valideurs.size(); i++) {
            valideursJSON.append(valideurs[i]);
        }
        QJsonDocument doc;
        doc.setArray(valideursJSON);
        query.bindValue(":emailValideurs", doc.toJson());

        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        this->id = query.lastInsertId().toInt();

        return true;
    }else{
        // TODO: modif

        query.prepare("UPDATE Transfert SET emailValideurs = :emailValideurs, date = :date WHERE id = :id");
        query.bindValue(":id", id);
        query.bindValue(":date", date);

        QJsonArray valideursJSON;
        for (int i = 0; i < valideurs.size(); i++) {
            valideursJSON.append(valideurs[i]);
        }
        QJsonDocument doc;
        doc.setArray(valideursJSON);
        query.bindValue(":emailValideurs", doc.toJson());

        if(!query.exec()) qWarning() << "Error: " << db.lastError();

        return true;
    }
}


QList<Transfert> Transfert::getTransfertOfCagnotte(int id, Cagnotte* cagnotte){
    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;
    QList<Transfert> list;

    query.prepare("SELECT id, titre, date, montant, emailCreateur, emailValideurs FROM Transfert WHERE idCagnotte = :id");
    query.bindValue(":id", id);

    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    while (query.next()) {
        Transfert t(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toFloat(), query.value(4).toString(), cagnotte);

        // set valideurs transfert
        QJsonDocument doc = QJsonDocument::fromJson(query.value(5).toByteArray());
        QJsonArray arr = doc.array();
        foreach(const QJsonValue& value, arr){
            t.valideurs.append(value.toString());
        }

        if(!t.estVide()) list.append(t);
    }

    return list;
}

void Transfert::valider(const QString& email){
    if(cagnotte->getSomme() < -montant) return;

    if(!valideurs.contains(email)) {
        QDate d = QDate::currentDate();
        date = d.toString("dd/MM/yyyy");
        valideurs.append(email);
    }
}

QList<QString> Transfert::getValideurs() const {
    return valideurs;
}

Utilisateur& Transfert::getCreateur(){
    return *cagnotte->getParticipant(createur);
}

QString Transfert::getTitre() const{
    return titre;
}

QString Transfert::getDate() const{
    return date;
}

float Transfert::getMontant() const{
    return montant;
}

bool Transfert::estVide() const{
    return titre.isEmpty();
}
