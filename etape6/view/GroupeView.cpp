#include "GroupeView.h"

#include "model/GroupePayement.h"
#include "model/Utilisateur.h"

GroupeView::GroupeView(QObject* parent) : QObject(parent) {}

void GroupeView::setGroupe(GroupePayement& groupe){
    this->groupe = &groupe;
}

QString GroupeView::getTitre(){
    if(groupe == nullptr) return "Null";
    return groupe->getTitre();
}

QString GroupeView::getType(){
    if(groupe == nullptr) return "Empty";
    return groupe->getType();
}
