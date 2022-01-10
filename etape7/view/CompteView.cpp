#include "CompteView.h"
#include <math.h>

CompteView::CompteView(QObject *parent) : GroupeView(parent){

}

CompteView::~CompteView(){
    // clear depenses
    qDebug() << "DELETE CompteView :" << this;

    qDeleteAll(depenses);
    depenses.clear();

    qDeleteAll(balances);
    balances.clear();
}

void CompteView::setGroupe(GroupePayement& groupe){
    GroupeView::setGroupe(groupe);

    updateDepenses();
    updateBalances();
}

void CompteView::updateDepenses(){
    Compte* c = (Compte*)this->groupe;

    // clear depenses
    if(!depenses.isEmpty()){
        qDeleteAll(depenses);
        depenses.clear();
    }

    // ajout des vues pour les groupes
    for (int i = 0; i < c->getDepensesSize(); i++) {
        DepenseView* depense = new DepenseView();
        depense->setCompte(this);

        depense->setDepense(c->getDepense(i));
        depenses.append(depense);
    }

    emit depensesChanged(depenses);
    emit totalChanged();
}

void CompteView::updateLastDepense(){
    Compte* c = (Compte*)this->groupe;

    DepenseView* depense = new DepenseView();
    depense->setCompte(this);
    depense->setDepense(c->getDepense(c->getDepensesSize()-1));
    depenses.append(depense);

    updateBalancesValue();

    emit depensesChanged(depenses);
    emit totalChanged();
}

void CompteView::updateBalances(){
    // clear depenses
    if(!balances.isEmpty()){
        qDeleteAll(balances);
        balances.clear();
    }

    // ajout des vues pour les groupes
    for (int i = 0; i < participants.size(); i++) {
        BalanceView* balance = new BalanceView();
        balance->setUtilisateur(participants[i]);
        balances.append(balance);
    }

    updateBalancesValue(); // set la valeur des balances
}

void CompteView::updateBalancesValue(){
    for (int i = 0; i < balances.size(); i++) {
        balances[i]->setValeur(0);
    }

    for (int i = 0; i < depenses.size(); i++) {
        DepenseView* d = depenses[i];

        for (int j = 0; j < balances.size(); j++) {
            BalanceView* b = balances[j];

            if(b->getUtilisateur()->getEmail() == d->getPayeur()->getEmail()) b->addValeur(d->getMontant() - (d->getMontant() / participants.size()));
            else b->addValeur(-(d->getMontant() / participants.size()));
        }
    }

    emit balancesChanged(balances);
}

// onUserAdded => addBalance + updateBalancesValue()

QList<DepenseView*> CompteView::getDepenses() const{
    return depenses;
}

QList<BalanceView*> CompteView::getBalances() const {
    return balances;
}

float CompteView::getBalanceValeur(QString utilisateur){
    for (int i = 0; i < balances.size(); i++) {
        if(balances[i]->getUtilisateur()->getEmail() == utilisateur) return balances[i]->getValeur();
    }
    return 0;
}

float CompteView::getTotal() const{
    float balance = 0;
    Compte* compte = (Compte*)this->groupe;
    for (int i = 0; i < compte->getDepensesSize(); i++) {
        balance += compte->getDepense(i).getMontant();
    }
    return balance;
}
