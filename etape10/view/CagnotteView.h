#ifndef CAGNOTTEVIEW_H
#define CAGNOTTEVIEW_H

#include "GroupeView.h"
#include "TransfertView.h"
#include "model/Cagnotte.h"
#include "model/Utilisateur.h"

/**
 * @brief Classe représentant la vue d'une cagnotte
 */
class CagnotteView : public GroupeView
{
    Q_OBJECT

    /**
     * @brief Liste des transferts
     */
    QList<TransfertView*> transferts;

    Q_PROPERTY(QList<UtilisateurView*> participants READ getParticipants NOTIFY participantsChanged)
    Q_PROPERTY(float total READ getTotal NOTIFY totalChanged)
    Q_PROPERTY(QList<TransfertView*> transferts READ getTransferts NOTIFY transfertsChanged)

public:
    explicit CagnotteView(QObject *parent = nullptr);

    /**
     * @brief Référencie le groupe à la vue
     * @param g compte à afficher
     */
    void setGroupe(GroupePayement& groupe) override;

    /**
     * @brief Init les vues des transferts
     */
    void initTransfert();
    /**
     * @brief Met à jour les transferts pour le dernier transfert ajouté
     */
    void updateAjoutTransfert();

    /**
     * @brief Retourne les vues des transferts lié à la cagnotte
     * @return transferts
     */
    QList<TransfertView*> getTransferts();
    /**
     * @brief Retourne le total de la cagnotte
     * @return total
     */
    float getTotal();

signals:
    void participantsChanged(QList<UtilisateurView*> participants);
    void totalChanged();
    void transfertsChanged(QList<TransfertView*> transferts);
};

#endif // CAGNOTTEVIEW_H
