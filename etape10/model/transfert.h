#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "DatabaseManager.h"
#include <QList>
#include <QString>
#include <QDate>

class Utilisateur;

class Cagnotte;

/**
 * @brief Classe repésentant les transferts dans les cagnottes
 *
 * @author Fabien
 */
class Transfert
{
    /**
     * @brief id du transfert
     */
    int id;
    /**
     * @brief titre du transfert
     */
    QString titre;

    /**
     * @brief date du transfert
     */
    QString date;

    /**
     * @brief montant du transfert
     */
    float montant;

    /**
     * @brief référence à la cagnotte lié au transfert
     */
    Cagnotte* cagnotte;

    /**
     * @brief créateur du transfert
     */
    QString createur;

    /**
     * @brief liste des emails des valideurs
     */
    QList<QString> valideurs;


public:
    /**
     * @brief Crée un transfert non enregistré dans la base de données (voir save())
     * @param titre titre du transfert
     * @param date date du transfert (dd/mm/yyyy)
     * @param montant montant du transfert
     * @param utilisateur createur du transfert
     * @param cagnotte cagnotte lié au transfert
     */
    Transfert(const QString& titre, const QString& date, const float& montant, const QString& createur, Cagnotte* cagnotte);
    ~Transfert();
private:
    /**
     * @brief Crée un transfert non enregistré dans la base de données (voir save())
     * @param id id du transfert
     * @param titre titre du transfert
     * @param date date du transfert (dd/mm/yyyy)
     * @param montant montant du transfert
     * @param utilisateur createur du transfert
     * @param cagnotte cagnotte lié au transfert
     */
    Transfert(const int& id, const QString& titre, const QString& date, const float& montant, const QString& createur, Cagnotte* cagnotte);

public:
    /**
     * @brief Retourne une liste des transfert lié a la cagnotte
     * @param idCagnotte id de la cagnotte
     * @param cagnotte référence à la cagnotte
     * @return liste des transferts
     */
    static QList<Transfert> getTransfertOfCagnotte(int idCompte, Cagnotte* cagnotte);

    /**
     * @brief Sauvegarde le transfert lié à un id de cagnotte dans la base de données
     * @param id id de la cagnotte
     * @return booléen vrai si tout c'est bien passé
     */
    bool save(int id);

    /**
     * @brief Retourne le créateur du transfert
     * @return créateur du transfert
     */
    Utilisateur& getCreateur();
    QList<QString> getValideurs();

    QString getTitre() const;
    QString getDate() const;
    float getMontant() const;
    bool estVide() const;
};

#endif // TRANSFERT_H
