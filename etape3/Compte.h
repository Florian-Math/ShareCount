#ifndef COMPTE_H
#define COMPTE_H

#include <QList>
#include "DatabaseManager.h"
#include "GroupePayement.h"

/**
 * @brief Classe représentant un compte
 *
 * @author Fabien
 */
class Compte : public GroupePayement
{

public:
    Compte(const QString& titre, const QString& description)
        : GroupePayement(titre, description){};
    ~Compte();
protected:
    Compte()
        : GroupePayement(){};
    Compte(const int id, const QString& titre, const QString& description)
        : GroupePayement(id, titre, description){};

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

};



#endif // COMPTE_H
