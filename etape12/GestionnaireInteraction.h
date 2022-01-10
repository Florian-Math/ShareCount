#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H

#include <QObject>
#include <QString>

#include "model/Utilisateur.h"
#include "view/UtilisateurView.h"
#include "view/GroupeView.h"
#include "view/CompteView.h"
#include "view/CagnotteView.h"


/**
 * @brief Classe gérant les interactions de l'utilisateur
 *
 * @author Florian & Fabien
 */
class GestionnaireInteraction : public QObject {
    Q_OBJECT
    /**
     * @brief l'utilisateur connecté
     */
    Utilisateur utilisateurCourant;
    /**
     * @brief vue de l'utilisateur connecté
     */
    UtilisateurView utilisateurCourantView;
    /**
     * @brief groupe courant
     */
    GroupePayement* groupeCourant;
    /**
     * @brief vue du groupe courant
     */
    GroupeView* groupeCourantView;

    Q_PROPERTY(UtilisateurView* utilisateur READ getUtilisateurCourantView CONSTANT)
    Q_PROPERTY(GroupeView* groupeCourant READ getGroupeCourantView NOTIFY groupeCourantChanged)

    Q_PROPERTY(QList<DepenseView*> equilibrage READ getEquilibrageView NOTIFY equilibrageChanged)
    Q_PROPERTY(QList<DepenseView*> equilibrageSauf READ getEquilibrageSaufView NOTIFY equilibrageSaufChanged)

public:
    explicit GestionnaireInteraction(QObject* parent = nullptr);
    ~GestionnaireInteraction();
    /**
     * @brief Connecte l'utilisateur
     * @param email email
     * @param mdp mot de passe
     * @return booléen vrai si la connexion s'est bien passée, faux sinon
     */
    Q_INVOKABLE bool connexion(const QString& email, const QString& mdp);
    /**
     * @brief Inscrit et connecte l'utilisateur
     * @param email email
     * @param nom nom
     * @param prenom prenom
     * @param mdp mot de passe
     * @return booléen vrai si la connexion s'est bien passée, faux sinon
     */
    Q_INVOKABLE bool inscription(const QString& email, const QString& nom, const QString& prenom, const QString& mdp);
    /**
     * @brief Déconnecte l'utilisateur courant
     */
    Q_INVOKABLE void deconnexion();
    /**
     * @brief Selectionne un groupe
     * @param noGroupe numéro du groupe dans la liste des groupes de l'utilisateur courant
     * @return booléen vrai si le groupe a bien été selectionné
     */
    Q_INVOKABLE bool selectionnerGroupe(const int& noGroupe);
    /**
     * @brief Crée un compte et l'assigne à l'utilisateur courant
     * @param titre titre du compte
     * @param description description du compte
     * @return booléen vrai si le compte a bien été créé
     */
    Q_INVOKABLE bool creerCompte(const QString& titre, const QString& description);
    /**
     * @brief Crée une cagnotte et l'assigne à l'utilisateur courant
     * @param titre titre de la cagnotte
     * @param description description de la cagnotte
     * @return booléen vrai si la cagnotte a bien été créée
     */
    Q_INVOKABLE bool creerCagnotte(const QString& titre, const QString& description);

    /**
     * @brief Ajoute une dépense au compte courant
     * @param titre titre de la dépense
     * @param date date de la dépense
     * @param montant montant de la dépense
     * @return booléen vrai si la dépense a bien été créée
     */
    Q_INVOKABLE bool ajouterDepense(const QString& titre, const QString& date, const QString& montant);

    /**
     * @brief Ajoute un transfert à la cagnotte courante
     * @param titre titre du transfert
     * @param montant montant du transfert
     * @return booléen vrai si le transfert a bien été créé
     */
    Q_INVOKABLE bool ajouterTransfert(const QString& titre, const QString& montant);

    /**
     * @brief Ajoute un utilisateur identifié par son email au groupe courant
     * @param email email de l'utilisateur
     * @return booléen vrai si l'utilisateur a bien été invité
     */
    Q_INVOKABLE bool inviterUtilisateur(const QString& email);

    /**
     * @brief Regle la dépense numéro numDepense
     * @param numDepense numéro de la dépense
     * @return booléen vrai si la dépense a bien été réglé
     */
    Q_INVOKABLE bool reglerDepense(const int& numDepense);

    /**
     * @brief Valide le transfert numéro numTransfert
     * @param numTransfert numéro du transfert
     * @return booléen vrai si le transfert a bien été validé
     */
    Q_INVOKABLE bool validerTransfert(const int& numTransfert);

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

    /**
     * @brief Retourne la vue de l'utilisateur courant
     * @return vue de l'utilisateur courant
     */
    UtilisateurView* getUtilisateurCourantView();

    /**
     * @brief Retourne la vue du groupe courant
     * @return vue du groupe courant
     */
    GroupeView* getGroupeCourantView();

    /**
     * @brief Retourne l'équilibrage de l'utilisateur courant
     * @return liste des vues des équilibrages
     */
    QList<DepenseView*> getEquilibrageView();
    /**
     * @brief Retourne l'équilibrage non concerné par l'utilisateur courant
     * @return liste des vues des équilibrages
     */
    QList<DepenseView*> getEquilibrageSaufView();

signals:
    void groupeCourantChanged();
    void equilibrageChanged(QList<DepenseView*>);
    void equilibrageSaufChanged(QList<DepenseView*>);

};


#endif // GESTIONNAIREINTERACTION_H
