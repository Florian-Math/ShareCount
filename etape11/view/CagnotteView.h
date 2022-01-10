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
    Q_PROPERTY(QList<TransfertView*> transfertsEnAttente READ getTransfertsEnAttente NOTIFY transfertsChanged)


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
     * @brief Met à jour la vue pour la validation d'un transfert
     */
    void updateValidationTransfert();

    /**
     * @brief Retourne les vues des transferts lié à la cagnotte
     * @return transferts
     */
    QList<TransfertView*> getTransferts();
    /**
     * @brief Retourne les vues des transferts en attente
     * @return transferts en attente
     */
    QList<TransfertView*> getTransfertsEnAttente();
    /**
     * @brief Retourne le total de la cagnotte
     * @return total
     */
    float getTotal();

signals:
    void participantsChanged(QList<UtilisateurView*> participants);
    void totalChanged();
    void transfertsChanged();
};

#endif // CAGNOTTEVIEW_H
