#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H

#include <QString>
#include "Utilisateur.h"

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
     * @brief groupe courant
     */
    GroupePayement* groupeCourant;

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
     * @brief Selectionne un groupe
     * @param noGroupe numéro du groupe dans la liste des groupes de l'utilisateur courant
     * @return booléen vrai si le groupe a bien été selectionné
     */
    bool selectionnerGroupe(const int noGroupe);
    /**
     * @brief Crée un compte et l'assigne à l'utilisateur courant
     * @param titre titre du compte
     * @param description description du compte
     * @return booléen vrai si le compte a bien été créé
     */
    bool creerCompte(const QString titre, const QString description);
    /**
     * @brief Crée une cagnotte et l'assigne à l'utilisateur courant
     * @param titre titre de la cagnotte
     * @param description description de la cagnotte
     * @return booléen vrai si la cagnotte a bien été créée
     */
    bool creerCagnotte(const QString titre, const QString description);
    /**
     * @brief Retourne l'utilisateur courant
     * @return utilisateur courant
     */
    Utilisateur* getUtilisateurCourant();
    /**
     * @brief Retourne le groupe courant
     * @return compte courant
     */
    GroupePayement* getGroupeCourant();
};

#endif // GESTIONNAIREINTERACTION_H
