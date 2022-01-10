#ifndef DEPENSE_H
#define DEPENSE_H

#include "DatabaseManager.h"
#include <QList>
#include <QString>
#include <QDate>

class Utilisateur;
class Compte;

/**
 * @brief Classe repésentant les dépenses dans les comptes
 *
 * @author Florian
 */
class Depense
{
    /**
     * @brief id de la dépense
     */
    int id;
    /**
     * @brief titre de la dépense
     */
    QString titre;
    /**
     * @brief date de la dépense (date sous format unix timestamp)
     */
    int date;
    /**
     * @brief montant de la dépense
     */
    float montant;

    /**
     * @brief compte lié à la dépense
     */
    Compte* compte;
    /**
     * @brief payeur de la dépense
     */
    Utilisateur* payeur;


public:
    Depense(const QString& titre, const int date, const float montant);
private:
    Depense(const int id, const QString& titre, const int date, const float montant);

public:
    /**
     * @brief Retourne une liste des dépenses lié au compte
     * @param idCompte id du compte
     * @param compte compte
     * @return liste des dépenses
     */
    static QList<Depense> getDepensesOfCompte(int idCompte, Compte* compte);

    /**
     * @brief Set le payeur de la dépense
     * @param u payeur
     */
    void setPayeur(Utilisateur* u);
    /**
     * @brief Retourne une référence au payeur de la dépense
     * @return référence au payeur
     */
    Utilisateur* getPayeur();

    /**
     * @brief Sauvegarde la dépense lié à un id de compte
     * @param id id du compte
     * @return booléen vrai si tout c'est bien passé
     */
    bool save(int id);

    QString getTitre() const;
    int getDate() const;
    float getMontant() const;
    bool estVide() const;

};

#endif // DEPENSE_H
