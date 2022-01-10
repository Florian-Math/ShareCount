#include "CagnotteView.h"

CagnotteView::CagnotteView(QObject *parent) : GroupeView(parent){

}

void CagnotteView::setGroupe(GroupePayement& groupe) {
    GroupeView::setGroupe(groupe);

    initTransfert();
}

float CagnotteView::getTotal(){
    Cagnotte* c = (Cagnotte*)this->groupe;
    return c->getSomme();
}

void CagnotteView::initTransfert(){
    Cagnotte* c = (Cagnotte*)this->groupe;

    // clear depenses
    if(!transferts.isEmpty()){
        qDeleteAll(transferts);
        transferts.clear();
    }

    // ajout des vues pour les groupes
    for (int i = 0; i < c->getTransfertsSize(); i++) {
        TransfertView* transfert = new TransfertView();
        transfert->setCagnotte(this);

        transfert->setTransfert(c->getTransfert(i));
        transferts.append(transfert);
    }
    emit transfertsChanged(transferts);
}

void CagnotteView::updateAjoutTransfert(){
    Cagnotte* c = (Cagnotte*)this->groupe;

    TransfertView* transfert = new TransfertView();
    transfert->setCagnotte(this);
    transfert->setTransfert(c->getTransfert(c->getTransfertsSize()-1));
    transferts.append(transfert);

    emit transfertsChanged(transferts);
    emit totalChanged();
}

QList<TransfertView*> CagnotteView::getTransferts(){
    return transferts;
}
