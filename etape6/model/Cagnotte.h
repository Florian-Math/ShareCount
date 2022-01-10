#ifndef CAGNOTTE_H
#define CAGNOTTE_H

#include <QList>
#include "DatabaseManager.h"
#include "GroupePayement.h"

/**
 * @brief Classe représentant une cagnotte
 *
 * @author Florian
 */
class Cagnotte : public GroupePayement
{


public:
    Cagnotte(const QString& titre, const QString& description);
    ~Cagnotte();
protected:
    Cagnotte();
    Cagnotte(const int id, const QString& titre, const QString& description);

public:
    /**
     * @brief Sauvegarde la cagnotte dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save();
    /**
     * @brief Retourne une cagnotte de la base de données via son id
     * @param id id de la cagnotte
     * @return cagnotte recherchée
     */
    static Cagnotte getCagnotte(const int id);

};



#endif // COMPTE_H
