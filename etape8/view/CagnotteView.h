#ifndef CAGNOTTEVIEW_H
#define CAGNOTTEVIEW_H

#include "GroupeView.h"
#include "model/Cagnotte.h"
#include "model/Utilisateur.h"

/**
 * @brief Classe représentant la vue d'une cagnotte
 */
class CagnotteView : public GroupeView
{
    Q_OBJECT

    Q_PROPERTY(QList<UtilisateurView*> participants READ getParticipants NOTIFY participantsChanged)

public:
    explicit CagnotteView(QObject *parent = nullptr);

    /**
     * @brief Référencie le groupe à la vue
     * @param g compte à afficher
     */
    void setGroupe(GroupePayement& groupe) override;

signals:
    void participantsChanged(QList<UtilisateurView*> participants);
};

#endif // CAGNOTTEVIEW_H
