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
    /**
     * @brief Crée une cagnotte non enregistré dans la base de données (voir save())
     * @param titre titre de la cagnotte
     * @param description description de la cagnotte
     */
    Cagnotte(const QString& titre, const QString& description);
    ~Cagnotte();
protected:
    /**
     * @brief Crée une cagnotte vide
     */
    Cagnotte();
    /**
     * @brief Crée une cagnotte déjà relié à la base de données
     * @param id id de la cagnotte dans la base de donnée
     * @param titre titre de la cagnotte
     * @param description description de la cagnotte
     */
    Cagnotte(const int& id, const QString& titre, const QString& description);

public:
    /**
     * @brief Sauvegarde la cagnotte dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save();
    /**
     * @brief Retourne une référence à la cagnotte de la base de données via son id (Attention: Cagnotte* est déclarée sur le tas (heap), ne pas oublier de libérer la mémoire avec delete)
     * @param id id de la cagnotte
     * @return cagnotte recherchée
     */
    static Cagnotte* getCagnotte(const int& id);

    /**
     * @brief Retourne le type du groupe (ici renvoie toujours Cagnotte)
     * @return type du groupe
     */
    QString getType() const;
};



#endif // COMPTE_H
