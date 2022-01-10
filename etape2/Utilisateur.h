#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QList>
#include "DatabaseManager.h"

class Compte;

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
    QList<Compte> comptes;

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
     * @brief Construit un utilisateur vide
     */
    Utilisateur();

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
     * @brief Retourne le compte numéro i de l'utilisateur (0 <= i < taille)
     * @param i numéro du compte
     * @return compte recherché
     */
    Compte* getCompte(int i);
    /**
     * @brief Ajoute un compte à l'utilisateur
     * @param c compte à ajouter
     */
    void ajouterCompte(Compte c);

    QString getEmail() const;
    QString getNom() const;
    QString getPrenom() const;
    QList<Compte>* getComptes();


    bool estVide() const;
};

#endif // UTILISATEUR_H
