/** @mainpage CPOA Documentation etape 1.
 **
 ** Cette partie implémente la connexion et l'inscription d'un Utilisateur dans la base de données
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
#include <QDebug>
#include <iostream>

#include <QTextStream>

void connexion(GestionnaireInteraction &inter);
void inscription(GestionnaireInteraction &inter);
void showMainMenu(GestionnaireInteraction &inter);
void showConnectedMenu(GestionnaireInteraction &inter);

enum class ConsoleState { MainMenu, Connected };

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
    std::cout << "Connecte en tant que " << inter.getUtilisateurCourant().getPrenom().toStdString() << " " << inter.getUtilisateurCourant().getNom().toStdString() << " (" << inter.getUtilisateurCourant().getEmail().toStdString() << ")" << std::endl << std:: endl
              << "  1 - Deconnexion" << std::endl
              << "  2 - Quitter" << std::endl
              << std::endl
              << "Numero de menu : ";

    std::getline(std::cin, line);
    switch (line[0]) {
        case '1':
            state = ConsoleState::MainMenu;
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
