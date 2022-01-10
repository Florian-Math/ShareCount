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
     * @brief date de la dépense
     */
    QString date;
    /**
     * @brief montant de la dépense
     */
    float montant;

    /**
     * @brief référence au compte lié à la dépense
     */
    Compte* compte;
    /**
     * @brief payeur de la dépense
     */
    QString payeur;

    QList<QString> participants;


public:
    /**
     * @brief Crée une depense non enregistré dans la base de données (voir save())
     * @param titre titre de la depense
     * @param date date de la depense
     * @param montant montant de la depense
     */
    Depense(const QString& titre, const QString& date, const float& montant, Compte* compte);
    ~Depense();
private:
    /**
     * @brief Crée une depense déjà lié à la base de données (voir save())
     * @param id id de la depense
     * @param titre titre de la depense
     * @param date date de la depense
     * @param montant montant de la depense
     */
    Depense(const int& id, const QString& titre, const QString& date, const float& montant, Compte* compte);

public:
    /**
     * @brief Retourne une liste des dépenses lié au compte
     * @param idCompte id du compte
     * @param compte référence au compte
     * @return liste des dépenses
     */
    static QList<Depense> getDepensesOfCompte(int idCompte, Compte* compte);

    /**
     * @brief Set le payeur de la dépense
     * @param u payeur
     */
    void setPayeur(const Utilisateur& u);

    /**
     * @brief Set le payeur de la dépense
     * @param email email du payeur
     */
    void setPayeur(const QString& email);

    void setCompte(Compte* compte);
    /**
     * @brief Retourne le payeur de la dépense
     * @return payeur de la dépense
     */
    Utilisateur& getPayeur();

    /**
     * @brief Ajoute un participant à la dépense
     * @param email email du participant
     * @return booléen vrai si l'utilisateur a bien été enregistré
     */
    bool ajouterParticipant(const QString& email);
    /**
     * @brief Retourne la liste des emails des participants
     * @return emails des participants
     */
    QList<QString> getParticipants();

    /**
     * @brief Sauvegarde la dépense lié à un id de compte dans la base de données
     * @param id id du compte
     * @return booléen vrai si tout c'est bien passé
     */
    bool save(int id);

    QString getTitre() const;
    QString getDate() const;
    float getMontant() const;
    bool estVide() const;
};

#endif // DEPENSE_H
