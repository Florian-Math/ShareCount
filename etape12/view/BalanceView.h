#ifndef BALANCEVIEW_H
#define BALANCEVIEW_H

#include <QObject>
#include "UtilisateurView.h"

/**
 * @brief Classe représentant la vue d'une balance
 */
class BalanceView : public QObject
{
    Q_OBJECT

    /**
     * @brief model de l'utilisateur
     */
    UtilisateurView* utilisateur;
    /**
     * @brief valeur de la balance
     */
    float valeur;

    Q_PROPERTY(UtilisateurView* utilisateur READ getUtilisateur CONSTANT)
    Q_PROPERTY(float valeur READ getValeur NOTIFY valeurChanged)

public:
    explicit BalanceView(QObject *parent = nullptr);
    BalanceView(UtilisateurView* u);

    /**
     * @brief Set la valeur de la balance
     * @param v valeur
     */
    void setValeur(float v);
    /**
     * @brief Ajoute la valeur v à la balance
     * @param v valeur
     */
    void addValeur(float v);

    /**
     * @brief Set la vue de l'utilisateur lié à cette balance
     * @param u utilisateur
     */
    void setUtilisateur(UtilisateurView* u);
    /**
     * @brief Retourne le model de l'utilisateur
     * @return utilisateur
     */
    UtilisateurView* getUtilisateur();
    /**
     * @brief Retourne la valeur de la balance
     * @return valeur
     */
    float getValeur();

signals:
    void valeurChanged();

};

#endif // BALANCEVIEW_H
