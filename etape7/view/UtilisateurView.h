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
     * @brief Met à jour les vues des groupes
     * @param groupe groupe ajouté
     */
    Q_INVOKABLE void updateGroupes();

    GroupeView* getGroupe(int i) const;
    QString getEmail() const;
    QString getNom() const;
    QString getPrenom() const;
    QList<GroupeView*> getGroupes() const;

signals:
    void groupesChanged(QList<GroupeView*>);

};

#endif // UTILISATEURVIEW_H
