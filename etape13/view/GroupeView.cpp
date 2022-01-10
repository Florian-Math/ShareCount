#include "GroupeView.h"

#include "UtilisateurView.h"
#include "model/GroupePayement.h"
#include "model/Utilisateur.h"
#include "model/Compte.h"

GroupeView::GroupeView(QObject* parent) : QObject(parent) {}
GroupeView::~GroupeView(){
    // clear participants
    qDeleteAll(participants);
    participants.clear();
}

void GroupeView::setGroupe(GroupePayement& g){
    groupe = &g;

    // clear participants
    if(!participants.isEmpty()){
        qDeleteAll(participants);
        participants.clear();
    }

    // ajout des vues pour les groupes
    for (int i = 0; i < groupe->getParticipants().size(); i++) {
        UtilisateurView* u = new UtilisateurView();
        u->setUtilisateur(groupe->getParticipant(i));
        participants.append(u);
    }

    emit participantsChanged(participants);
}

void GroupeView::updateAjoutParticipant(){
    UtilisateurView* u = new UtilisateurView();
    u->setUtilisateur(groupe->getParticipant(groupe->getParticipants().size()-1));
    participants.append(u);

    emit participantsChanged(participants);
}

QString GroupeView::getTitre() const {
    if(groupe == nullptr) return "Null";
    return groupe->getTitre();
}

QString GroupeView::getDescription() const {
    if(groupe == nullptr) return "Null";
    return groupe->getDescription();
}

QString GroupeView::getType() const {
    if(groupe == nullptr) return "Empty";
    return groupe->getType();
}

QList<UtilisateurView*> GroupeView::getParticipants() const {
    return participants;
}

int GroupeView::getParticipantsSize() const {
    return participants.size();
}

UtilisateurView* GroupeView::getParticipant(int i){
    return participants[i];
}

UtilisateurView* GroupeView::getParticipant(const Utilisateur& u){
    for (int i = 0; i < participants.size(); i++) {
        if(participants[i]->getEmail() == u.getEmail()) return participants[i];
    }
    return nullptr;
}

UtilisateurView* GroupeView::getParticipant(const QString& email){
    for (int i = 0; i < participants.size(); i++) {
        if(participants[i]->getEmail() == email) return participants[i];
    }
    return nullptr;
}

GroupePayement* GroupeView::getGroupe(){
    return groupe;
}
