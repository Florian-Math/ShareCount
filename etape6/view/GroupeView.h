#ifndef GROUPEVIEW_H
#define GROUPEVIEW_H

#include <QObject>

class GroupePayement;

/**
 * @brief Classe représentant un groupe
 */
class GroupeView : public QObject
{
    Q_OBJECT

    /**
     * @brief model du groupe
     */
    GroupePayement* groupe = nullptr;

    Q_PROPERTY(QString titre READ getTitre CONSTANT)
    Q_PROPERTY(QString type READ getType CONSTANT)

public:
    explicit GroupeView(QObject *parent = nullptr);

    /**
     * @brief Référencie le groupe à la vue
     * @param g compte à afficher
     */
    void setGroupe(GroupePayement& groupe);

    QString getTitre();
    QString getType();
};

#endif // GROUPEVIEW_H
