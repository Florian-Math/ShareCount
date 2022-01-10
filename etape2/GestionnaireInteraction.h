#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H

#include <QString>
#include "Utilisateur.h"
#include "Compte.h"

/**
 * @brief Classe gérant les interactions de l'utilisateur
 *
 * @author Florian
 */
class GestionnaireInteraction {

    /**
     * @brief l'utilisateur connecté
     */
    Utilisateur utilisateurCourant;
    /**
     * @brief compte courant
     */
    Compte* compteCourant;

public:
    GestionnaireInteraction();
    /**
     * @brief Connecte l'utilisateur
     * @param email email
     * @param mdp mot de passe
     * @return booléen vrai si la connexion s'est bien passée, faux sinon
     */
    bool connexion(const QString email, const QString mdp);
    /**
     * @brief Inscrit et connecte l'utilisateur
     * @param email email
     * @param nom nom
     * @param prenom prenom
     * @param mdp mot de passe
     * @return booléen vrai si la connexion s'est bien passée, faux sinon
     */
    bool inscription(const QString email, const QString nom, const QString prenom, const QString mdp);
    /**
     * @brief Selectionne un compte
     * @param numéro du compte dans la liste des comptes de l'utilisateur courant
     * @return booléen vrai si le compte a bien été selectionné
     */
    bool selectionnerCompte(const int noCompte);
    /**
     * @brief Crée un compte et l'assigne à l'utilisateur courant
     * @param titre titre du compte
     * @param description description du compte
     * @return booléen vrai si le compte a bien été créé
     */
    bool creerCompte(const QString titre, const QString description);
    /**
     * @brief Retourne l'utilisateur courant
     * @return utilisateur courant
     */
    Utilisateur* getUtilisateurCourant();
    /**
     * @brief Retourne le compte courant
     * @return compte courant
     */
    Compte* getCompteCourant();
};

#endif // GESTIONNAIREINTERACTION_H
