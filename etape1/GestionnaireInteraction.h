#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H

#include "Utilisateur.h"

/**
 * @brief Classe gérant les interactions de l'utilisateur
 *
 * @author Florian
 */
class GestionnaireInteraction {

    /**
     * @brief Pointeur de l'utilisateur connecté
     */
    Utilisateur* utilisateurCourant;

public:
    ~GestionnaireInteraction();
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
     * @brief Retourne l'utilisateur courant
     * @return utilisateur courant
     */
    Utilisateur getUtilisateurCourant() const;
};

#endif // GESTIONNAIREINTERACTION_H
