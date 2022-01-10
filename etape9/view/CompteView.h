#ifndef COMPTEVIEW_H
#define COMPTEVIEW_H

#include "GroupeView.h"
#include "DepenseView.h"
#include "BalanceView.h"
#include "model/Compte.h"
#include "model/Utilisateur.h"

/**
 * @brief Classe représentant la vue d'un compte
 */
class CompteView : public GroupeView
{
    Q_OBJECT

    /**
     * @brief liste des vues des dépenses
     */
    QList<DepenseView*> depenses;
    /**
     * @brief liste des vues des balances
     */
    QList<BalanceView*> balances;
    /**
     * @brief liste des vues des équilibrage
     */
    QList<DepenseView*> equilibrages;

    Q_PROPERTY(QList<DepenseView*> depenses READ getDepenses NOTIFY depensesChanged)
    Q_PROPERTY(QList<BalanceView*> balances READ getBalances NOTIFY balancesChanged)
    Q_PROPERTY(float maxBalanceValue READ getMaxBalanceValue NOTIFY maxBalanceValueChanged)
    Q_PROPERTY(float total READ getTotal NOTIFY totalChanged)

    Q_PROPERTY(QList<UtilisateurView*> participants READ getParticipants NOTIFY participantsChanged) // de groupe

public:
    explicit CompteView(QObject *parent = nullptr);
    ~CompteView();

    /**
     * @brief Référencie le groupe à la vue
     * @param g compte à afficher
     */
    void setGroupe(GroupePayement& groupe) override;
    /**
     * @brief Met à jour la liste des participants par rapport au dernier participant ajouté
     */
    void updateAjoutParticipant() override;

    /**
     * @brief Initialise les vues des dépenses
     */
    void initDepenses();
    /**
     * @brief Met à jour les dépenses par rapport a la dernière dépense ajouté
     */
    void updateAjoutDepense();
    /**
     * @brief Initialise les vues des balances
     */
    void initBalances();
    /**
     * @brief Met à jour la valeur de toutes les balances
     */
    void updateValeurBalances();
    /**
     * @brief Met à jour l'équilibrage
     */
    void updateEquilibrage();

    /**
     * @brief Retourne la liste des vues des dépenses
     * @return dépenses
     */
    QList<DepenseView*> getDepenses() const;
    /**
     * @brief Retourne la liste des vues des balances
     * @return balances
     */
    QList<BalanceView*> getBalances() const;
    /**
     * @brief Retourne la liste des équilibrages lié à un utilisateur
     * @param email email de l'utilisateur
     * @return dépenses
     */
    QList<DepenseView*> getEquilibrage(const QString& email) const;
    /**
     * @brief Retourne la liste des équilibrages non lié à un utilisateur
     * @param email email de l'utilisateur
     * @return dépenses
     */
    QList<DepenseView*> getEquilibrageSauf(const QString& email) const;
    /**
     * @brief Retourne la valeur de la balance d'un utilisateur
     * @param utilisateur email de l'utilisateur
     * @return valeur balance
     */
    Q_INVOKABLE float getBalanceValeur(QString utilisateur);
    /**
     * @brief Retourne la valeur maximale ou minimal des balances (tjs positif)
     * @return valeur
     */
    float getMaxBalanceValue() const;
    /**
     * @brief Retourne le total du compte
     * @return total
     */
    float getTotal() const;

signals:
    void depensesChanged(QList<DepenseView*>);
    void balancesChanged(QList<BalanceView*>);
    void totalChanged();
    void participantsChanged(QList<UtilisateurView*> participants);
    void maxBalanceValueChanged();
};

#endif // COMPTEVIEW_H
