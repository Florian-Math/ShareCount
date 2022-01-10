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

GroupePayement::GroupePayement(const int id, const QString& titre, const QString& description)
{
    this->id = id;
    this->titre = titre;
    this->description = description;
    this->participants = {};
}

void GroupePayement::ajouterParticipant(const Utilisateur& u){
    participants.append(u);
}

QString GroupePayement::getTitre() const {
    return titre;
}

QString GroupePayement::getDescription() const {
    return description;
}

QString GroupePayement::getType() const {
    return type;
}

QList<Utilisateur>* GroupePayement::getParticipants(){
    return &participants;
}

bool GroupePayement::estVide() const {
    return titre.isEmpty();
}

