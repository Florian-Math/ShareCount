#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QList>
#include "DatabaseManager.h"
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

    QList<Compte> comptes;
    QList<Cagnotte> cagnottes;

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
     * @brief Ajoute un compte à l'utilisateur
     * @param c compte à ajouter
     */
    void ajouterCompte(Compte c);
    /**
     * @brief Ajoute une cagnotte à l'utilisateur
     * @param c cagnotte à ajouter
     */
    void ajouterCagnotte(Cagnotte c);

    QString getEmail() const;
    QString getNom() const;
    QString getPrenom() const;


    bool estVide() const;
};

#endif // UTILISATEUR_H
