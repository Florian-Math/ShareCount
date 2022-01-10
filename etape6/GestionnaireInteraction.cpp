#include "GestionnaireInteraction.h"

#include "model/Compte.h"
#include "model/Cagnotte.h"
#include "model/Depense.h"

GestionnaireInteraction::GestionnaireInteraction(QObject *parent) : QObject(parent){

}

bool GestionnaireInteraction::connexion(const QString email, const QString mdp) {
    Utilisateur u = Utilisateur::connexion(email, mdp);

    if(!u.estVide()){
        utilisateurCourant = u;
        utilisateurCourantView.setUtilisateur(utilisateurCourant);
        return true;
    }
    else return false;
}

bool GestionnaireInteraction::inscription(const QString email, const QString nom, const QString prenom, const QString mdp) {
    Utilisateur u(email, nom, prenom, mdp);

    if(u.save()){
        utilisateurCourant = u;
        utilisateurCourantView.setUtilisateur(utilisateurCourant);
        return true;
    }
    else return false;
}

bool GestionnaireInteraction::selectionnerGroupe(const int noGroupe) {
    if(noGroupe < 0 || noGroupe >= utilisateurCourant.getGroupeSize()) return false;

    groupeCourant = utilisateurCourant.getGroupe(noGroupe);
    groupeCourantView = utilisateurCourantView.getGroupe(noGroupe);
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

bool GestionnaireInteraction::ajouterDepense(const QString titre, const int date, const float montant){
    Compte* c = dynamic_cast<Compte*>(groupeCourant);
    Depense d(titre, date, montant);
    if(d.estVide()) return false;

    c->ajouterDepense(d);
    c->getDepense(c->getDepensesSize()-1)->setPayeur(&utilisateurCourant);

    if(c->save()) return true;
    else return false;
}

Utilisateur* GestionnaireInteraction::getUtilisateurCourant(){
    return &utilisateurCourant;
}

GroupePayement* GestionnaireInteraction::getGroupeCourant(){
    return groupeCourant;
}
