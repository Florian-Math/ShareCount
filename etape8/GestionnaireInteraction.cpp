#include "GestionnaireInteraction.h"

#include "model/Compte.h"
#include "model/Cagnotte.h"
#include "model/Depense.h"

GestionnaireInteraction::GestionnaireInteraction(QObject *parent) : QObject(parent){

}

GestionnaireInteraction::~GestionnaireInteraction(){
    qDebug() << "DELETE GesetionnaireInteraction";
    utilisateurCourant.dispose();
}

bool GestionnaireInteraction::connexion(const QString email, const QString mdp) {
    // recup utilisateur dans la base de données
    Utilisateur u = Utilisateur::connexion(email, mdp);

    // si il est valide
    if(!u.estVide()){
        // set utilisateur courant
        utilisateurCourant = u;

        // set vues
        utilisateurCourantView.setUtilisateur(utilisateurCourant);

        return true;
    }
    else return false;
}

bool GestionnaireInteraction::inscription(const QString email, const QString nom, const QString prenom, const QString mdp) {
    // création utilisateur
    Utilisateur u(email, nom, prenom, mdp);

    // si l'insertion c'est bien passé
    if(u.save()){
        // set utilisateur
        utilisateurCourant = u;

        // set vue
        utilisateurCourantView.setUtilisateur(utilisateurCourant);

        return true;
    }
    else return false;
}

bool GestionnaireInteraction::selectionnerGroupe(const int noGroupe) {
    if(noGroupe < 0 || noGroupe >= utilisateurCourant.getGroupeSize()) return false;

    groupeCourant = utilisateurCourant.getGroupe(noGroupe);
    groupeCourantView = utilisateurCourantView.getGroupe(noGroupe);
    emit groupeCourantChanged();

    return true;
}

bool GestionnaireInteraction::creerCompte(const QString titre, const QString description) {
    // crée un compte
    Compte* c = new Compte(titre, description);

    // verif validité compte
    if(c->estVide()) {
        delete c;
        return false;
    }

    // si l'insertion c'est bien passé ajoute le compte à l'utilisateur
    if(c->save()){
        c->ajouterParticipant(utilisateurCourant);
        utilisateurCourant.ajouterCompte(c);
        utilisateurCourantView.updateAjoutGroupe(c);
        return true;
    }
    else{
        delete c;
        return false;
    }
}

bool GestionnaireInteraction::creerCagnotte(const QString titre, const QString description) {
    Cagnotte* c = new Cagnotte(titre, description);

    // verif validité cagnotte
    if(c->estVide()) {
        delete c;
        return false;
    }

    // si l'insertion c'est bien passé ajoute la cagnotte à l'utilisateur
    if(c->save()){
        c->ajouterParticipant(utilisateurCourant);
        utilisateurCourant.ajouterCagnotte(c);
        utilisateurCourantView.updateAjoutGroupe(c);
        return true;
    }
    else{
        delete c;
        return false;
    }
}

bool GestionnaireInteraction::ajouterDepense(const QString titre, const QString date, const QString montant){
    Compte* c = (Compte*)groupeCourant;
    CompteView* cv = (CompteView*)groupeCourantView;

    float montantF = std::stof(montant.toStdString());
    Depense d(titre, date, montantF, c);

    if(d.estVide()) return false;

    c->ajouterDepense(d);
    c->getDepense(c->getDepensesSize()-1).setPayeur(utilisateurCourant);

    cv->updateAjoutDepense();

    if(c->save()) return true;
    else {
        qWarning() << "ATTENTION : Depense non valide dans le compte"; // n'arrive normalement jamais
        return false;
    }
}

bool GestionnaireInteraction::inviterUtilisateur(const QString& email){
    Utilisateur u = Utilisateur::getUtilisateur(email);

    if(u.estVide()) return false;

    if(groupeCourant->ajouterParticipant(u)){
        groupeCourantView->updateAjoutParticipant();
        return true;
    }
    else return false;
}

Utilisateur* GestionnaireInteraction::getUtilisateurCourant(){
    return &utilisateurCourant;
}

GroupePayement* GestionnaireInteraction::getGroupeCourant(){
    return groupeCourant;
}
