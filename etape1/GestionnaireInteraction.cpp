#include "GestionnaireInteraction.h"

bool GestionnaireInteraction::connexion(const QString email, const QString mdp) {
    Utilisateur* u = Utilisateur::connexion(email, mdp);

    if(u != nullptr){
        utilisateurCourant = u;
        return true;
    }
    else return false;
}

bool GestionnaireInteraction::inscription(const QString email, const QString nom, const QString prenom, const QString mdp) {
    Utilisateur* u = new Utilisateur(email, nom, prenom, mdp);

    if(u->save()){
        utilisateurCourant = u;
        return true;
    }else{
        delete u;
        return false;
    }
}

GestionnaireInteraction::~GestionnaireInteraction(){
    if(utilisateurCourant != nullptr) {
        delete utilisateurCourant;
        utilisateurCourant = nullptr;
    }
}

Utilisateur GestionnaireInteraction::getUtilisateurCourant() const{
    return *utilisateurCourant;
}
