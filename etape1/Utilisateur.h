#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>

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
     * @brief Sauvegarde l'utilisateur dans la base de données
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save();
    /**
     * @brief Récupère l'utilisateur dans la base de données
     * @param email email
     * @param mdp mot de passe
     * @return pointeur vers l'utilisateur recherché
     */
    static Utilisateur* connexion(const QString email, const QString mdp);

    QString getEmail() const;
    QString getNom() const;
    QString getPrenom() const;
};

#endif // UTILISATEUR_H
