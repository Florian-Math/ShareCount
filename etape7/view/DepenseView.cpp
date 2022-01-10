#include "DepenseView.h"
#include "CompteView.h"

DepenseView::DepenseView(QObject *parent) : QObject(parent)
{

}

DepenseView::~DepenseView(){
    qDebug() << "DELETE DepenseView :" << this;
}

void DepenseView::setDepense(Depense& depense){
    this->depense = &depense;
    payeur = compte->getParticipant(depense.getPayeur());
}

void DepenseView::setCompte(CompteView* compte){
    this->compte = compte;
}

QString DepenseView::getTitre() const {
    return depense->getTitre();
}

float DepenseView::getMontant() const {
    return depense->getMontant();
}

UtilisateurView* DepenseView::getPayeur() {
    return payeur;
}
