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

    Q_PROPERTY(QList<DepenseView*> depenses READ getDepenses NOTIFY depensesChanged)
    Q_PROPERTY(QList<BalanceView*> balances READ getBalances NOTIFY balancesChanged)
    Q_PROPERTY(float total READ getTotal NOTIFY totalChanged)

    Q_PROPERTY(QList<UtilisateurView*> participants READ getParticipants CONSTANT) // de groupe

public:
    explicit CompteView(QObject *parent = nullptr);
    ~CompteView();

    /**
     * @brief Initialise les vues des dépenses
     */
    void updateDepenses();
    /**
     * @brief Met à jour les dépenses par rapport a la dernière dépense ajouté
     */
    void updateLastDepense();
    /**
     * @brief Initialise les vues des balances
     */
    void updateBalances();
    /**
     * @brief Met à jour la valeur de toutes les balances
     */
    void updateBalancesValue();

    /**
     * @brief Référencie le groupe à la vue
     * @param g compte à afficher
     */
    void setGroupe(GroupePayement& groupe);

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
     * @brief Retourne la valeur de la balance d'un utilisateur
     * @param utilisateur email de l'utilisateur
     * @return valeur balance
     */
    Q_INVOKABLE float getBalanceValeur(QString utilisateur);
    /**
     * @brief Retourne le total du compte
     * @return total
     */
    float getTotal() const;

signals:
    void depensesChanged(QList<DepenseView*>);
    void balancesChanged(QList<BalanceView*>);
    void totalChanged();
};

#endif // COMPTEVIEW_H
