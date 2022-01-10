#ifndef TRANSFERTVIEW_H
#define TRANSFERTVIEW_H

#include <QObject>
#include "model/Transfert.h"
#include "UtilisateurView.h"

class CagnotteView;

/**
 * @brief Classe représentant la vue d'un transfert
 */
class TransfertView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString titre READ getTitre CONSTANT)
    Q_PROPERTY(float montant READ getMontant CONSTANT)
    Q_PROPERTY(UtilisateurView* createur READ getCreateur CONSTANT)
    Q_PROPERTY(QList<UtilisateurView*> valideurs READ getValideurs CONSTANT)

    /**
     * @brief transfert à afficher
     */
    Transfert* transfert = nullptr;
    /**
     * @brief vue du createur du transfert
     */
    UtilisateurView* createur = nullptr;
    /**
     * @brief vue de la cagnotte assigné au transfert
     */
    CagnotteView* cagnotte = nullptr;

public:
    explicit TransfertView(QObject *parent = nullptr);
    ~TransfertView();

    /**
     * @brief Référencie le transfert à la vue
     * @param transfert transfert à afficher
     */
    void setTransfert(Transfert& transfert);
    /**
     * @brief Référencie la cagnotte à la vue
     * @param cagnotte cagnotte lié au transfert
     */
    void setCagnotte(CagnotteView* cagnotte);

    /**
     * @brief Vérifie si l'email recherché est présent dans la liste des valideurs
     * @param email email de l'utilisateur recherché
     * @return booléen vrai si l'utilisateur est bien présent dans la liste des valideurs
     */
    Q_INVOKABLE bool containValideur(const QString email);

    /**
     * @brief Retourne le titre du transfert
     * @return titre
     */
    QString getTitre() const;
    /**
     * @brief Retourne le montant du transfert
     * @return montant
     */
    float getMontant() const;
    /**
     * @brief Retourne la vue du créateur du transfert
     * @return vue du créateur
     */
    UtilisateurView* getCreateur();
    /**
     * @brief Retourne la vue de la cagnotte lié au transfert
     * @return vue cagnotte lié
     */
    CagnotteView* getCagnotte();
    /**
     * @brief Retourne le model du transfert
     * @return transfert
     */
    Transfert* getTransfert() const;
    /**
     * @brief Retourne la liste des vues des valideurs
     * @return liste des valideurs
     */
    QList<UtilisateurView*> getValideurs();

signals:

};

#endif // TRANSFERTVIEW_H
