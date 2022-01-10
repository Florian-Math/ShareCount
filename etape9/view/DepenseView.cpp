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

QList<UtilisateurView*> DepenseView::getParticipants(){
    QList<UtilisateurView*> parts;
    for(int i = 0; i < depense->getParticipants().size(); i++){
        UtilisateurView* p = compte->getParticipant(depense->getParticipants().at(i));
        if(p != nullptr) parts.append(p);
    }

    return parts;
}

Depense* DepenseView::getDepense() const {
    return depense;
}
