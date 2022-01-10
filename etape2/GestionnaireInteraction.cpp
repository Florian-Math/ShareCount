#include "GestionnaireInteraction.h"

GestionnaireInteraction::GestionnaireInteraction(){}

bool GestionnaireInteraction::connexion(const QString email, const QString mdp) {
    Utilisateur u = Utilisateur::connexion(email, mdp);

    if(!u.estVide()){
        utilisateurCourant = u;
        return true;
    }
    else return false;
}

bool GestionnaireInteraction::inscription(const QString email, const QString nom, const QString prenom, const QString mdp) {
    Utilisateur u(email, nom, prenom, mdp);

    if(u.save()){
        utilisateurCourant = u;
        return true;
    }
    else return false;
}

bool GestionnaireInteraction::selectionnerCompte(const int noCompte) {
    if(noCompte < 0 || noCompte >= utilisateurCourant.getComptes()->size()) return false;

    compteCourant = utilisateurCourant.getCompte(noCompte);
    return true;
}

bool GestionnaireInteraction::creerCompte(const QString titre, const QString description) {
    Compte c(titre, description);
    if(c.estVide()) return false;

    c.ajouterParticipant(utilisateurCourant);
    utilisateurCourant.ajouterCompte(c);

    if(c.save()){
        compteCourant = utilisateurCourant.getCompte(utilisateurCourant.getComptes()->size()-1);
        return true;
    }
    else return false;
}

Utilisateur* GestionnaireInteraction::getUtilisateurCourant(){
    return &utilisateurCourant;
}

Compte* GestionnaireInteraction::getCompteCourant(){
    return compteCourant;
}
