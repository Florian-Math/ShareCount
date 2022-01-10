#ifndef CAGNOTTE_H
#define CAGNOTTE_H

#include <QList>
#include "DatabaseManager.h"
#include "GroupePayement.h"

#include "Transfert.h"

/**
 * @brief Classe représentant une cagnotte
 *
 * @author Florian & Fabien
 */
class Cagnotte : public GroupePayement
{
    /**
     * @brief somme de la cagnotte
     */
    float somme;
    /**
     * @brief liste des transferts de la cagnotte
     */
    QList<Transfert> transferts;

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
    bool save() override;
    /**
     * @brief Retourne une référence à la cagnotte de la base de données via son id (Attention: Cagnotte* est déclarée sur le tas (heap), ne pas oublier de libérer la mémoire avec delete)
     * @param id id de la cagnotte
     * @return cagnotte recherchée
     */
    static Cagnotte* getCagnotte(const int& id);

    /**
     * @brief Ajoute un transfert à la cagnotte et calcul la nouvelle somme si le transfert est positif
     * @param t transfert à ajouter
     */
    void ajouterTransfert(const Transfert& t);

    /**
     * @brief Retourne la somme présente de la cagnotte
     * @return somme de la cagnotte
     */
    float getSomme() const;

    /**
     * @brief Recalcul la somme de la cagnotte
     */
    void updateSomme();

    /**
     * @brief Retourne le transfert numéro i
     * @param i numéro du transfert
     * @return transfert recherché
     */
    Transfert& getTransfert(int i);
    /**
     * @brief Retourne le nombre de transfert
     * @return nombre de transfert
     */
    int getTransfertsSize();
    /**
     * @brief Retourne le type du groupe (ici renvoie toujours Cagnotte)
     * @return type du groupe
     */
    QString getType() const override;
};



#endif // COMPTE_H
