/** @mainpage CPOA Documentation etape 4.
 **
 ** Cette partie implémente l'ajout de Depense dans un Compte
 **
 ** Pour lancer le projet:
 ** <ul>
 **     <li>lancez console.cpp en mode console (Dans qtcreator Projets>Build & Run>Run>Run in terminal)</li>
 ** </ul>
 **
 ** Le projet a été testé sur:
 ** <ul>
 **     <li>Windows 10</li>
 **     <li>Arch linux [KDE Plasma]</li>
 ** </ul>
 **/

#include "DatabaseManager.h"
#include "GestionnaireInteraction.h"

#include "Depense.h"
#include "Compte.h"

#include <QList>
#include <QDebug>
#include <iostream>
#include <ctime>
#include <iomanip>

void connexion(GestionnaireInteraction &inter);
void inscription(GestionnaireInteraction &inter);
void creerDepense(GestionnaireInteraction &inter);

void showMainMenu(GestionnaireInteraction &inter);
void showConnectedMenu(GestionnaireInteraction &inter);
void showCompteMenu(GestionnaireInteraction &inter);
void showCagnotteMenu(GestionnaireInteraction &inter);

enum class ConsoleState { MainMenu, Connected, Compte, Cagnotte };

std::string line;
bool end = false;
ConsoleState state = ConsoleState::MainMenu;

int main(int argc, char *argv[])
{

    GestionnaireInteraction inter;

    while(!end){
        // clear
        for (int i=0; i< 100; i++) {
            std::cout << std::endl;
        }

        switch (state) {
            case ConsoleState::MainMenu:
                showMainMenu(inter);
                break;
            case ConsoleState::Connected:
                showConnectedMenu(inter);
                break;
            case ConsoleState::Compte:
                showCompteMenu(inter);
                break;
            case ConsoleState::Cagnotte:
                showCagnotteMenu(inter);
                break;
        }


    }

    return 0;
}

void showMainMenu(GestionnaireInteraction &inter){
    std::cout << "  1 - Connexion" << std::endl
              << "  2 - Inscription" << std::endl
              << "  3 - Quitter" << std::endl
              << std::endl
              << "Numero de menu : ";

    std::getline(std::cin, line);
    switch (line[0]) {
        case '1':
            connexion(inter);
            break;
        case '2':
            inscription(inter);
            break;
        case '3':
            end = true;
            break;
    }
}

void showConnectedMenu(GestionnaireInteraction &inter){
    std::cout << "Connecte en tant que " << inter.getUtilisateurCourant()->getPrenom().toStdString() << " " << inter.getUtilisateurCourant()->getNom().toStdString() << " (" << inter.getUtilisateurCourant()->getEmail().toStdString() << ")" << std::endl << std:: endl;

    Utilisateur* u = inter.getUtilisateurCourant();

    int size = u->getGroupeSize();
    for (int i = 0; i < size; i++) {
        std::cout << "  " << (i+1) << " - " << u->getGroupe(i)->getTitre().toStdString() << std::endl;
    }

    std::cout << "  " << (size+1) << " - Ajouter compte" << std::endl
              << "  " << (size+2) << " - Ajouter cagnotte" << std::endl
              << "  " << (size+3) << " - Deconnexion" << std::endl
              << "  " << (size+4) << " - Quitter" << std::endl
              << std::endl
              << "Numero de menu : ";

    std::getline(std::cin, line);
    for (int i=0; i < size; i++) {
        if(line == std::to_string(i+1)){

            if(Compte* c = dynamic_cast<Compte*>(u->getGroupe(i))){
                state = ConsoleState::Compte;
            }else{
                state = ConsoleState::Cagnotte;
            }
            inter.selectionnerGroupe(i);
        }
    }
    if(line == std::to_string(size+1)) { // ajouter compte

        std::cout << "titre : ";
        std::string titre;
        std::getline(std::cin, titre);

        std::cout << "description : ";
        std::string description;
        std::getline(std::cin, description);

        if(!inter.creerCompte(QString::fromStdString(titre), QString::fromStdString(description))){
            std::cout << std::endl << "Erreur creation de compte" << std::endl;
            std::cout << "Appuyez sur <Enter> pour continuer";
            std::getline(std::cin, line);
        }
    }
    else if(line == std::to_string(size+2)) { // ajouter cagnotte

        std::cout << "titre : ";
        std::string titre;
        std::getline(std::cin, titre);

        std::cout << "description : ";
        std::string description;
        std::getline(std::cin, description);

        if(!inter.creerCagnotte(QString::fromStdString(titre), QString::fromStdString(description))){
            std::cout << std::endl << "Erreur creation de cagnotte" << std::endl;
            std::cout << "Appuyez sur <Enter> pour continuer";
            std::getline(std::cin, line);
        }
    }
    else if(line == std::to_string(size+3)) state = ConsoleState::MainMenu;
    else if(line == std::to_string(size+4)) end = true;
}

void showCompteMenu(GestionnaireInteraction &inter){
    Compte* compte = dynamic_cast<Compte*>(inter.getGroupeCourant());

    std::cout << "Connecte sur le compte " << inter.getGroupeCourant()->getTitre().toStdString() << std::endl
              << inter.getGroupeCourant()->getDescription().toStdString() << std::endl << std:: endl;
    std::cout << "Participants :" << std::endl;

    QList<Utilisateur>* participants = inter.getGroupeCourant()->getParticipants();
    for (int i = 0; i < participants->size(); i++) {
        std::cout << " - " << participants->at(i).getPrenom().toStdString() << " " << participants->at(i).getNom().toStdString() << " (" << participants->at(i).getEmail().toStdString() << ")" << std::endl;
    }

    std::cout << "Depenses :" << std::endl;
    for (int i = 0; i < compte->getDepensesSize(); i++) {
        Depense* d = compte->getDepense(i);
        std::time_t time = d->getDate();
        std::cout << " - " << d->getTitre().toStdString() << " " << std::put_time(std::localtime(&time), "%d-%m-%y") << " " << d->getMontant() << " " << d->getPayeur()->getEmail().toStdString() << std::endl;
    }


    std::cout << std::endl;

    std::cout << "  1 - Creer depense" << std::endl
              << "  2 - Retour" << std::endl
              << "  3 - Quitter" << std::endl
              << std::endl
              << "Numero de menu : ";

    std::getline(std::cin, line);
    switch (line[0]) {
        case '1':
            creerDepense(inter);
            break;
        case '2':
            state = ConsoleState::Connected;
            break;
        case '3':
            end = true;
            break;
    }
}

void showCagnotteMenu(GestionnaireInteraction &inter){
    std::cout << "Connecte sur la cagnotte " << inter.getGroupeCourant()->getTitre().toStdString() << std::endl
              << inter.getGroupeCourant()->getDescription().toStdString() << std::endl << std:: endl;
    std::cout << "Participants :" << std::endl;

    QList<Utilisateur>* comptes = inter.getGroupeCourant()->getParticipants();
    for (int i = 0; i < comptes->size(); i++) {
        std::cout << "  - " << comptes->at(i).getPrenom().toStdString() << " " << comptes->at(i).getNom().toStdString() << " (" << comptes->at(i).getEmail().toStdString() << ")" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "  1 - Retour" << std::endl
              << "  2 - Quitter" << std::endl
              << std::endl
              << "Numero de menu : ";

    std::getline(std::cin, line);
    switch (line[0]) {
        case '1':
            state = ConsoleState::Connected;
            break;
        case '2':
            end = true;
            break;
    }
}

void connexion(GestionnaireInteraction &inter){

    std::cout << "email : ";
    std::string email;
    std::getline(std::cin, email);

    std::cout << "mot de passe : ";
    std::string mdp;
    std::getline(std::cin, mdp);

    if (inter.connexion(QString::fromStdString(email), QString::fromStdString(mdp))){
        state = ConsoleState::Connected;
    }else{
        std::cout << std::endl << "informations erronees" << std::endl;
        std::cout << "Appuyez sur <Enter> pour continuer";
        std::getline(std::cin, email);
    }
}

void inscription(GestionnaireInteraction &inter){
    std::cout << "email : ";
    std::string email;
    std::getline(std::cin, email);

    std::cout << "nom : ";
    std::string nom;
    std::getline(std::cin, nom);

    std::cout << "prenom : ";
    std::string prenom;
    std::getline(std::cin, prenom);

    std::cout << "mot de passe : ";
    std::string mdp;
    std::getline(std::cin, mdp);

    if(inter.inscription(QString::fromStdString(email), QString::fromStdString(nom), QString::fromStdString(prenom), QString::fromStdString(mdp))){
        state = ConsoleState::Connected;
    }else{
        std::cout << std::endl << "Compte deja existant" << std::endl;
        std::cout << "Appuyez sur <Enter> pour continuer";
        std::getline(std::cin, email);
    }
}

void creerDepense(GestionnaireInteraction &inter){
    std::cout << "titre : ";
    std::string titre;
    std::getline(std::cin, titre);

    std::cout << "montant : ";
    std::string montant;
    std::getline(std::cin, montant);

    if(!inter.ajouterDepense(QString::fromStdString(titre), std::time(0), std::stof(montant))){
        std::cout << std::endl << "Erreur creation de la depense" << std::endl;
        std::cout << "Appuyez sur <Enter> pour continuer";
        std::getline(std::cin, line);
    }
}
