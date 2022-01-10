#ifndef GROUPEPAYEMENT_H
#define GROUPEPAYEMENT_H

#include <QList>
#include <string>
#include "DatabaseManager.h"

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
    /**
     * @brief représente l'enregistrement dans la base de données
     */
    bool registered;

public:
    /**
     * @brief Crée un groupe
     * @param titre titre du groupe
     * @param description description du groupe
     */
    GroupePayement(const QString& titre, const QString& description);
    virtual ~GroupePayement(){};
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
    GroupePayement(const int id, const QString& titre, const QString& description);
public:
    /**
     * @brief Sauvegarde le groupe dans la base
     * @return vrai si il n'y a pas eu d'erreurs lors de l'insertion dans la base
     */
    virtual bool save() = 0;
    /**
     * @brief Ajoute un participant au groupe
     */
    void ajouterParticipant(Utilisateur u);

    QString getTitre() const;
    QString getDescription() const;
    QList<Utilisateur>* getParticipants();

    bool estVide() const;
};



#endif // COMPTE_H
