#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H

#include <QObject>
#include <QString>

#include "model/Utilisateur.h"
#include "view/UtilisateurView.h"
#include "view/GroupeView.h"


/**
 * @brief Classe gérant les interactions de l'utilisateur
 *
 * @author Florian
 */
class GestionnaireInteraction : public QObject {
    Q_OBJECT
    /**
     * @brief l'utilisateur connecté
     */
    Utilisateur utilisateurCourant;
    UtilisateurView utilisateurCourantView;
    /**
     * @brief groupe courant
     */
    GroupePayement* groupeCourant;
    GroupeView* groupeCourantView;

    Q_PROPERTY(UtilisateurView* utilisateur READ getUtilisateurCourantView CONSTANT)
    Q_PROPERTY(GroupeView* groupeCourant READ getGroupeCourantView CONSTANT)

public:
    explicit GestionnaireInteraction(QObject* parent = nullptr);
    /**
     * @brief Connecte l'utilisateur
     * @param email email
     * @param mdp mot de passe
     * @return booléen vrai si la connexion s'est bien passée, faux sinon
     */
    Q_INVOKABLE bool connexion(const QString email, const QString mdp);
    /**
     * @brief Inscrit et connecte l'utilisateur
     * @param email email
     * @param nom nom
     * @param prenom prenom
     * @param mdp mot de passe
     * @return booléen vrai si la connexion s'est bien passée, faux sinon
     */
    Q_INVOKABLE bool inscription(const QString email, const QString nom, const QString prenom, const QString mdp);
    /**
     * @brief Selectionne un groupe
     * @param noGroupe numéro du groupe dans la liste des groupes de l'utilisateur courant
     * @return booléen vrai si le groupe a bien été selectionné
     */
    Q_INVOKABLE bool selectionnerGroupe(const int noGroupe);
    /**
     * @brief Crée un compte et l'assigne à l'utilisateur courant
     * @param titre titre du compte
     * @param description description du compte
     * @return booléen vrai si le compte a bien été créé
     */
    Q_INVOKABLE bool creerCompte(const QString titre, const QString description);
    /**
     * @brief Crée une cagnotte et l'assigne à l'utilisateur courant
     * @param titre titre de la cagnotte
     * @param description description de la cagnotte
     * @return booléen vrai si la cagnotte a bien été créée
     */
    Q_INVOKABLE bool creerCagnotte(const QString titre, const QString description);
    /**
     * @brief Retourne l'utilisateur courant
     * @return utilisateur courant
     */
    Q_INVOKABLE bool ajouterDepense(const QString titre, const int date, const float montant);

    Utilisateur* getUtilisateurCourant();
    /**
     * @brief Retourne le groupe courant
     * @return compte courant
     */
    GroupePayement* getGroupeCourant();

    UtilisateurView* getUtilisateurCourantView(){
        return &utilisateurCourantView;
    }

    GroupeView* getGroupeCourantView(){
        return groupeCourantView;
    }

};


#endif // GESTIONNAIREINTERACTION_H
