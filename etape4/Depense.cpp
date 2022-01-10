#include "Depense.h"
#include "Compte.h"
#include "Utilisateur.h"

Depense::Depense(const int id, const QString& titre, const int date, const float montant)
{
    this->id = id;
    this->titre = titre;
    this->date = date;
    this->montant = montant;
}

Depense::Depense(const QString& titre, const int date, const float montant){
    this->id = -1;
    this->titre = titre;
    this->date = date;
    this->montant = montant;
}

bool Depense::save(int idCompte){
    if(estVide()) return false;

    QSqlDatabase db = DatabaseManager::getDatabase();
    QSqlQuery query;

    // si il n'est pas dans la base
    if(id == -1){
        // insert
        query.prepare("INSERT INTO Depense(titre, date, montant, idCompte, emailPayeur) VALUES(:titre, :date, :montant, :idCompte, :emailPayeur)");
        query.bindValue(":titre", titre);
        query.bindValue(":date", date);
        query.bindValue(":montant", montant);
        query.bindValue(":idCompte", idCompte);
        query.bindValue(":emailPayeur", payeur->getEmail());
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

    query.prepare("SELECT id, titre, date, montant, emailPayeur FROM Depense WHERE idCompte = :id");
    query.bindValue(":id", id);

    if(!query.exec()) qWarning() << "Error: " << db.lastError();
    while (query.next()) {
        Depense d(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt(), query.value(3).toFloat());
        d.setPayeur(compte->getParticipant(query.value(4).toString()));
        if(!d.estVide()) list.append(d);
    }

    return list;
}

Utilisateur* Depense::getPayeur(){
    return payeur;
}

void Depense::setPayeur(Utilisateur *u){
    payeur = u;
}

QString Depense::getTitre() const{
    return titre;
}

int Depense::getDate() const{
    return date;
}

float Depense::getMontant() const{
    return montant;
}

bool Depense::estVide() const{
    return titre.isEmpty();
}
