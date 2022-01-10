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

    /**
     * @brief utilisateur à afficher
     */
    Utilisateur* utilisateur;
    /**
     * @brief vue des groupes de l'utilisateur
     */
    QList<GroupeView*> groupes;

    Q_PROPERTY(QString email READ getEmail CONSTANT)
    Q_PROPERTY(QList<GroupeView*> groupes READ getGroupes NOTIFY groupesChanged)

public:
    explicit UtilisateurView(QObject *parent = nullptr);
    void setUtilisateur(Utilisateur& u);

    /**
     * @brief Met à jour les vues
     */
    Q_INVOKABLE void updateView();

    GroupeView* getGroupe(int i);
    QString getEmail();
    QList<GroupeView*> getGroupes();

signals:
    void groupesChanged(QList<GroupeView*>);

};

#endif // UTILISATEURVIEW_H
