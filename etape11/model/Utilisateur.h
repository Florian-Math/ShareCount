#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QList>
#include "DatabaseManager.h"

#include "GroupePayement.h"
#include "Compte.h"
#include "Cagnotte.h"

/**
 * @brief Classe représentant l'utilisateur
 *
 * @author Florian
 */
class Utilisateur
{
    /**
     * @brief email de l'utilisateur
     */
    QString email;
    /**
     * @brief nom de l'utilisateur
     */
    QString nom;
    /**
     * @brief prenom de l'utilisateur
     */
    QString prenom;
    /**
     * @brief mot de passe de l'utilisateur
     */
    QString mdp;
    /**
     * @brief représente l'enregistrement dans la base de données
     */
    bool registered;

    /**
     * @brief liste des comptes lié à l'utilisateur
     */
    QList<Compte*> comptes;
    /**
     * @brief liste des cagnottes lié à l'utilisateur
     */
    QList<Cagnotte*> cagnottes;

public:
    /**
     * @brief Construit un nouvel utilisateur (il n'est pas enregistré dans la base de données tant que la fonction save() n'est pas appelée)
     * @param email
     * @param nom
     * @param prenom
     * @param mdp
     */
    Utilisateur(const QString& email, const QString& nom, const QString& prenom, const QString& mdp);
    /**
     * @brief Construit un utilisateur ne pouvant pas être enregistré
     * @param email
     * @param nom
     * @param prenom
     * @param mdp
     */
    Utilisateur(const QString& email, const QString& nom, const QString& prenom);
    /**
     * @brief Construit un utilisateur vide
     */
    Utilisateur();
    ~Utilisateur();

public:
    /**
     * @brief Sauvegarde l'utilisateur dans la base de données
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save();
    /**
     * @brief Récupère l'utilisateur dans la base de données
     * @param email email
     * @param mdp mot de passe
     * @return l'utilisateur recherché
     */
    static Utilisateur connexion(const QString& email, const QString& mdp);
    /**
     * @brief Retourne l'utilisateur de la base de données via son email
     * @param email email de l'utilisateur
     * @return utilisateur recherché
     */
    static Utilisateur getUtilisateur(const QString& email);

    /**
     * @brief Retourne un pointeur vers le groupe numéro i de l'utilisateur (0 <= i < getGroupeSize())
     * @param i numéro du groupe
     * @return groupe recherché
     */
    GroupePayement* getGroupe(int i);
    /**
     * @brief Retourne le nombre de groupes
     * @return nombre de groupes
     */
    int getGroupeSize();
    /**
     * @brief Retourne le nombre de comptes
     * @return nombre de comptes
     */
    int getCompteSize();
    /**
     * @brief Ajoute un compte à l'utilisateur
     * @param c compte à ajouter
     */
    void ajouterCompte(Compte* c);
    /**
     * @brief Ajoute une cagnotte à l'utilisateur
     * @param c cagnotte à ajouter
     */
    void ajouterCagnotte(Cagnotte* c);

    /**
     * @brief Retourne l'email de l'utilisateur
     * @return email
     */
    QString getEmail() const;
    /**
     * @brief Retourne le nom de l'utilisateur
     * @return nom
     */
    QString getNom() const;
    /**
     * @brief Retourne le prenom de l'utilisateur
     * @return prenom
     */
    QString getPrenom() const;
    /**
     * @brief Retourne booléen vrai si l'utilisateur est vide
     * @return booléen
     */
    bool estVide() const;

    /**
     * @brief Detruit les comptes et cagnottes associés
     */
    void dispose();
};

#endif // UTILISATEUR_H
