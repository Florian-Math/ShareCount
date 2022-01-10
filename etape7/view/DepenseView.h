#ifndef DEPENSEVIEW_H
#define DEPENSEVIEW_H

#include <QObject>
#include "model/Depense.h"
#include "UtilisateurView.h"

class CompteView;

/**
 * @brief Classe représentant la vue d'une dépense
 */
class DepenseView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString titre READ getTitre CONSTANT)
    Q_PROPERTY(float montant READ getMontant CONSTANT)
    Q_PROPERTY(UtilisateurView* payeur READ getPayeur CONSTANT)

    /**
     * @brief model de la dépense
     */
    Depense* depense = nullptr;
    /**
     * @brief vue du payeur
     */
    UtilisateurView* payeur = nullptr;
    /**
     * @brief vue du compte lié
     */
    CompteView* compte = nullptr;

public:
    explicit DepenseView(QObject *parent = nullptr);
    ~DepenseView();

    /**
     * @brief Référencie la dépense à la vue
     * @param depense dépense à afficher
     */
    void setDepense(Depense& depense);
    /**
     * @brief Référencie le compte à la vue
     * @param compte compte lié à la dépense
     */
    void setCompte(CompteView* compte);

    QString getTitre() const;
    float getMontant() const;
    UtilisateurView* getPayeur();
    CompteView* getCompte();

signals:

};

#endif // DEPENSEVIEW_H
