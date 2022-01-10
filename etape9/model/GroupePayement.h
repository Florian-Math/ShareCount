#ifndef GROUPEPAYEMENT_H
#define GROUPEPAYEMENT_H

#include <QList>
#include <string>
#include "DatabaseManager.h"

//#include "Utilisateur.h"
class Utilisateur;

/**
 * @brief Classe représentant un groupe
 *
 * @author Fabien
 */
class GroupePayement
{
protected:
    /**
     * @brief id du groupe dans la base de données (-1 si le groupe n'est pas enregistré)
     */
    int id;
    /**
     * @brief titre du groupe
     */
    QString titre;
    /**
     * @brief description du groupe
     */
    QString description;
    /**
     * @brief liste des participants
     */
    QList<Utilisateur> participants;

public:
    /**
     * @brief Crée un groupe
     * @param titre titre du groupe
     * @param description description du groupe
     */
    GroupePayement(const QString& titre, const QString& description);
    virtual ~GroupePayement();
protected:
    /**
     * @brief Crée un groupe vide
     */
    GroupePayement();
    /**
     * @brief Crée un groupe déjà lié à la base de données
     * @param id id du groupe dans la base de données
     * @param titre titre du groupe
     * @param description description du groupe
     */
    GroupePayement(const int& id, const QString& titre, const QString& description);
public:
    /**
     * @brief Sauvegarde le groupe dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    virtual bool save() = 0;
    /**
     * @brief Ajoute un utilisateur au groupe en l'enregistrant dans la base de données (seulement si le groupe est lié à la base voir save())
     * @param u utilisateur à ajouter au groupe
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    virtual bool ajouterParticipant(const Utilisateur& u);

    /**
     * @brief Retourne le titre du groupe
     * @return titre du groupe
     */
    QString getTitre() const;
    /**
     * @brief Retourne la description du groupe
     * @return description du groupe
     */
    QString getDescription() const;
    /**
     * @brief Retourne la liste des participants
     * @return liste des participants
     */
    QList<Utilisateur>& getParticipants();
    /**
     * @brief Retourne le participant numéro i
     * @param i numéro du participant
     * @return participant
     */
    Utilisateur& getParticipant(int i);

    /**
     * @brief Retourne le type de groupe (Compte ou Cagnotte)
     * @return type de groupe
     */
    virtual QString getType() const = 0;

    bool estVide() const;
};



#endif // COMPTE_H
