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

    emit transfertsChanged();
}

void CagnotteView::updateAjoutTransfert(){
    Cagnotte* c = (Cagnotte*)this->groupe;

    TransfertView* transfert = new TransfertView();
    transfert->setCagnotte(this);
    transfert->setTransfert(c->getTransfert(c->getTransfertsSize()-1));
    transferts.append(transfert);

    emit transfertsChanged();
    emit totalChanged();
}

void CagnotteView::updateValidationTransfert(){
    emit transfertsChanged();
    emit totalChanged();
}

QList<TransfertView*> CagnotteView::getTransferts(){
    QList<TransfertView*> res;
    for(int i = 0; i < transferts.size(); i++){
        if(transferts[i]->getMontant() > 0 || transferts[i]->getValideurs().size() >= 2)
            res.append(transferts[i]);
    }
    return res;
}

QList<TransfertView*> CagnotteView::getTransfertsEnAttente(){
    QList<TransfertView*> res;
    for(int i = 0; i < transferts.size(); i++){
        if(transferts[i]->getMontant() < 0 && transferts[i]->getValideurs().size() < 2)
            res.append(transferts[i]);
    }
    return res;
}
