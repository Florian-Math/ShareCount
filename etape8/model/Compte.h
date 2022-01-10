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
    bool save();
    /**
     * @brief Retourne une référence au compte de la base de données via son id (Attention: Compte* est déclaré sur le tas (heap), ne pas oublier de libérer la mémoire avec delete)
     * @param id id du compte
     * @return compte recherché
     */
    static Compte* getCompte(const int id);

    /**
     * @brief Retourne une référence à l'utilisateur correspondant à l'email ou nullptr s'il n'est pas trouvé
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
     * @brief Retourne le type du groupe (ici renvoie toujours Compte)
     * @return type du groupe
     */
    QString getType() const;
};



#endif // COMPTE_H
