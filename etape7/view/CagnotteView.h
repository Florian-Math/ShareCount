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

    Q_PROPERTY(QList<UtilisateurView*> participants READ getParticipants CONSTANT)

public:
    explicit CagnotteView(QObject *parent = nullptr);
};

#endif // CAGNOTTEVIEW_H
