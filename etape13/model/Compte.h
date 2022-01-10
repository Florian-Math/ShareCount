#ifndef COMPTE_H
#define COMPTE_H

#include <QList>
#include "DatabaseManager.h"
#include "GroupePayement.h"

#include "Depense.h"

/**
 * @brief Classe représentant un compte
 *
 * @authors Fabien
 * @authors Florian
 */
class Compte : public GroupePayement
{
    /**
     * @brief liste des dépenses
     */
    QList<Depense> depenses;
    /**
     * @brief balance selon l'email des utilisateurs
     */
    QHash<QString, float> balances;
    /**
     * @brief liste des dépenses qui doivent être faite afin d'équilibrer le compte
     */
    QList<Depense> equilibrages;

public:
    /**
     * @brief Crée un compte non enregistré dans la base de données (voir save())
     * @param titre titre du compte
     * @param description du compte
     */
    Compte(const QString& titre, const QString& description);
    ~Compte();
protected:
    /**
     * @brief Crée un compte vide
     */
    Compte();
    /**
     * @brief Crée un compte déjà relié à base de données
     * @param id id du compte dans la base de données
     * @param titre titre du compte
     * @param description du compte
     */
    Compte(const int& id, const QString& titre, const QString& description);

public:
    /**
     * @brief Sauvegarde le compte dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save() override;
    /**
     * @brief Retourne une référence au compte de la base de données via son id (Attention: Compte* est déclaré sur le tas (heap), ne pas oublier de libérer la mémoire avec delete)
     * @param id id du compte
     * @return compte recherché
     */
    static Compte* getCompte(const int id);

    /**
     * @brief Ajoute un utilisateur au groupe en l'enregistrant dans la base de données (seulement si le groupe est lié à la base voir save())
     * @param u utilisateur à ajouter au groupe
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool ajouterParticipant(const Utilisateur& u) override;
    /**
     * @brief Clos le groupe si la balance du compte est vide
     * @return booléen vrai si le groupe a bien été clos
     */
    bool clore() override;

    /**
     * @brief Ajoute une dépense et met à jour les balances et équilibrages
     * @param d dépense
     * @return booléen vrai si tout c'est bien passé
     */
    bool ajouterDepense(const Depense& d);

    /**
     * @brief Met à jour les balances de tout les participants
     */
    void updateBalances();
    /**
     * @brief Met à jour tout les équilibrages requit
     */
    void updateEquilibrage();

    /**
     * @brief Retourne la balance de l'utilisateur renseigné
     * @param email email de l'utilisateur de la balance
     * @return balance recherchée
     */
    float getBalance(const QString& email);
    /**
     * @brief Retourne la dépense numéro i
     * @param i numéro de la dépense
     * @return dépense
     */
    Depense& getDepense(int i);
    /**
     * @brief Retourne le nombre de dépense
     * @return nombre de dépense
     */
    int getDepensesSize();

    /**
     * @brief Regle la dépense numéro i
     * @param i numéro de la dépense à régler
     * @return booléen vrai si la dépense a bien été réglé
     */
    bool reglerDepense(int i);

    /**
     * @brief Retourne l'équilibrage numéro i
     * @param i numéro de l'équilibrage
     * @return dépense recherché
     */
    Depense& getEquilibrage(int i);
    /**
     * @brief Retourne le nombre d'équilibrage
     * @return nombre d'équilibrage
     */
    int getEquilibragesSize();

    /**
     * @brief Retourne le type du groupe (ici renvoie toujours Compte)
     * @return type du groupe
     */
    QString getType() const override;
};



#endif // COMPTE_H
