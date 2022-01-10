#include "TransfertView.h"
#include "CagnotteView.h"

TransfertView::TransfertView(QObject *parent) : QObject(parent)
{

}

TransfertView::~TransfertView(){
    qDebug() << "DELETE TransfertView :" << this;
}

void TransfertView::setTransfert(Transfert& transfert){
    this->transfert = &transfert;
    createur = cagnotte->getParticipant(transfert.getCreateur());
}

void TransfertView::setCagnotte(CagnotteView* cagnotte){
    this->cagnotte = cagnotte;
}

QString TransfertView::getTitre() const {
    return transfert->getTitre();
}

float TransfertView::getMontant() const {
    return transfert->getMontant();
}

UtilisateurView* TransfertView::getCreateur() {
    return createur;
}

QList<UtilisateurView*> TransfertView::getValideurs(){
    QList<UtilisateurView*> vals;
    for(int i = 0; i < transfert->getValideurs().size(); i++){
        UtilisateurView* p = cagnotte->getParticipant(transfert->getValideurs().at(i));
        if(p != nullptr) vals.append(p);
    }

    return vals;
}

Transfert* TransfertView::getTransfert() const {
    return transfert;
}
