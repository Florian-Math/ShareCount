#ifndef UTILISATEURVIEW_H
#define UTILISATEURVIEW_H

#include <QObject>
#include "model/Utilisateur.h"
#include "GroupeView.h"

/**
 * @brief Classe représentant la vue d'un utilisateur
 */
class UtilisateurView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString email READ getEmail CONSTANT)
    Q_PROPERTY(QString nom READ getNom CONSTANT)
    Q_PROPERTY(QString prenom READ getPrenom CONSTANT)
    Q_PROPERTY(QList<GroupeView*> groupes READ getGroupes NOTIFY groupesChanged)

    /**
     * @brief utilisateur à afficher
     */
    Utilisateur* utilisateur;
    /**
     * @brief vue des groupes de l'utilisateur
     */
    QList<GroupeView*> groupes;

public:
    explicit UtilisateurView(QObject *parent = nullptr);
    ~UtilisateurView();

    /**
     * @brief Référencie l'utilisateur à la vue
     * @param u utilisateur à afficher
     */
    void setUtilisateur(Utilisateur& u);

    /**
     * @brief Met à jour les vues des groupes selon le dernier ajout
     * @param groupe groupe ajouté
     */
    void updateAjoutGroupe(GroupePayement* groupe);

    /**
     * @brief Retourne la vue du groupe numéro 1
     * @param i numéro du groupe
     * @return vue du groupe recherché
     */
    GroupeView* getGroupe(int i) const;
    /**
     * @brief Retourne l'email de l'utilisateur
     * @return email de l'utilisateur
     */
    QString getEmail() const;
    /**
     * @brief Retourne le nom de l'utilisateur
     * @return nom de l'utilisateur
     */
    QString getNom() const;
    /**
     * @brief Retourne le prenom de l'utilisateur
     * @return prenom de l'utilisateur
     */
    QString getPrenom() const;
    /**
     * @brief Retourne les vues des groupes
     * @return vues des groupes
     */
    QList<GroupeView*> getGroupes() const;

signals:
    void groupesChanged(QList<GroupeView*>);

};

#endif // UTILISATEURVIEW_H
