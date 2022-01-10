#ifndef COMPTE_H
#define COMPTE_H

#include <QList>
#include "DatabaseManager.h"
#include "GroupePayement.h"

#include "Depense.h"

/**
 * @brief Classe représentant un compte
 *
 * @author Fabien
 */
class Compte : public GroupePayement
{
    /**
     * @brief Liste des dépenses
     */
    QList<Depense> depenses;

public:
    Compte(const QString& titre, const QString& description);
    ~Compte();
protected:

    Compte();
    Compte(const int id, const QString& titre, const QString& description);

public:
    /**
     * @brief Sauvegarde le compte dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save();
    /**
     * @brief Retourne un compte de la base de données via son id
     * @param id id du compte
     * @return compte recherché
     */
    static Compte getCompte(const int id);

    /**
     * @brief Retourne une référence à l'utilisateur correspondant à l'email
     * @param email email de l'utilisateur
     * @return pointeur vers l'utilisateur
     */
    Utilisateur* getParticipant(const QString& email);
    /**
     * @brief Ajoute une dépense
     * @param d dépense
     * @return booléen vrai si tout c'est bien passé
     */
    bool ajouterDepense(const Depense& d);
    /**
     * @brief Retourne une référence à la dépense numéro i
     * @param i numéro de la dépense
     * @return pointeur vers la dépense
     */
    Depense* getDepense(int i);
    /**
     * @brief Retourne le nombre de dépense
     * @return nombre de dépense
     */
    int getDepensesSize();
};



#endif // COMPTE_H
