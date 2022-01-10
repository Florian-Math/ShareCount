#ifndef COMPTE_H
#define COMPTE_H

#include <QList>
#include "Utilisateur.h"
#include "DatabaseManager.h"

/**
 * @brief Classe représentant les comptes
 *
 * @author Fabien
 */
class Compte
{
    /**
     * @brief id du compte dans la base de données (-1 si le compte n'est pas enregistré)
     */
    int id;
    /**
     * @brief titre du compte
     */
    QString titre;
    /**
     * @brief description du compte
     */
    QString description;
    /**
     * @brief liste des participants
     */
    QList<Utilisateur> participants;
    /**
     * @brief représente l'enregistrement dans la base de données
     */
    bool registered;

public:
    /**
     * @brief Crée un compte
     * @param titre titre du compte
     * @param description description du compte
     */
    Compte(const QString& titre, const QString& description);
private:
    /**
     * @brief Crée un compte vide
     */
    Compte();
    /**
     * @brief Crée un compte déjà lié à la base de données
     * @param id id du compte dans la base de données
     * @param titre titre du compte
     * @param description description du compte
     */
    Compte(const int id, const QString& titre, const QString& description);

public:
    /**
     * @brief Sauvegarde le compte dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    bool save();
    /**
     * @brief Ajoute un participant au compte
     */
    void ajouterParticipant(Utilisateur u);
    /**
     * @brief Retourne un compte de la base de données via son id
     * @param id id du compte
     * @return compte recherché
     */
    static Compte getCompte(const int id);

    QString getTitre() const;
    QString getDescription() const;
    QList<Utilisateur>* getParticipants();

    bool estVide() const;


};



#endif // COMPTE_H
