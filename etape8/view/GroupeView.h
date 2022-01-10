#ifndef GROUPEVIEW_H
#define GROUPEVIEW_H

#include <QObject>

class UtilisateurView;
class GroupePayement;
class Utilisateur;

/**
 * @brief Classe représentant un groupe
 */
class GroupeView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString titre READ getTitre CONSTANT)
    Q_PROPERTY(QString description READ getDescription CONSTANT)
    Q_PROPERTY(QString type READ getType CONSTANT)
    Q_PROPERTY(int participantsSize READ getParticipantsSize CONSTANT)
    //Q_PROPERTY(QList<UtilisateurView*> participants READ getParticipants NOTIFY participantsChanged)

protected:
    /**
     * @brief model du groupe
     */
    GroupePayement* groupe = nullptr;
    /**
     * @brief vue des participants du groupe
     */
    QList<UtilisateurView*> participants;

public:
    explicit GroupeView(QObject *parent = nullptr);
    virtual ~GroupeView();

    /**
     * @brief Référencie le groupe à la vue
     * @param g compte à afficher
     */
    virtual void setGroupe(GroupePayement& g);
    /**
     * @brief Met à jour la liste des participants par rapport au dernier participant ajouté
     */
    virtual void updateAjoutParticipant();

    QString getTitre() const;
    QString getDescription() const;
    QString getType() const;

    /**
     * @brief Retourne les vues des participants
     * @return participants
     */
    QList<UtilisateurView*> getParticipants() const;
    /**
     * @brief Retourne le nombre de participants
     * @return nombre de participants
     */
    int getParticipantsSize() const;
    /**
     * @brief Retourne la vue du participant u
     * @param u utilisateur
     * @return vue de l'utilisateur
     */
    UtilisateurView* getParticipant(const Utilisateur& u);
    /**
     * @brief Retourne la vue du participant numéro i
     * @param i numéro du participant
     * @return vue de l'utilisateur
     */
    UtilisateurView* getParticipant(int i);

signals:
    void participantsChanged(QList<UtilisateurView*> participants);
};

#endif // GROUPEVIEW_H
