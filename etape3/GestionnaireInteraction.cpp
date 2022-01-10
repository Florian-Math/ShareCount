#include "GestionnaireInteraction.h"
#include "Compte.h"
#include "Cagnotte.h"

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

bool GestionnaireInteraction::selectionnerGroupe(const int noGroupe) {
    if(noGroupe < 0 || noGroupe >= utilisateurCourant.getGroupeSize()) return false;

    groupeCourant = utilisateurCourant.getGroupe(noGroupe);
    return true;
}

bool GestionnaireInteraction::creerCompte(const QString titre, const QString description) {
    Compte c(titre, description);
    if(c.estVide()) return false;

    c.ajouterParticipant(utilisateurCourant);
    utilisateurCourant.ajouterCompte(c);

    return c.save();
}

bool GestionnaireInteraction::creerCagnotte(const QString titre, const QString description) {
    Cagnotte c(titre, description);
    if(c.estVide()) return false;

    c.ajouterParticipant(utilisateurCourant);
    utilisateurCourant.ajouterCagnotte(c);

    return c.save();
}

Utilisateur* GestionnaireInteraction::getUtilisateurCourant(){
    return &utilisateurCourant;
}

GroupePayement* GestionnaireInteraction::getGroupeCourant(){
    return groupeCourant;
}
