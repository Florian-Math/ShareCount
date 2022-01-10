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

    qDeleteAll(equilibrages);
    equilibrages.clear();
}

void CompteView::setGroupe(GroupePayement& groupe){
    GroupeView::setGroupe(groupe);

    initDepenses();
    initBalances();
    updateEquilibrage();
}

void CompteView::initDepenses(){
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

void CompteView::updateAjoutDepense(){
    Compte* c = (Compte*)this->groupe;

    DepenseView* depense = new DepenseView();
    depense->setCompte(this);
    depense->setDepense(c->getDepense(c->getDepensesSize()-1));
    depenses.append(depense);

    updateValeurBalances();
    updateEquilibrage();

    emit depensesChanged(depenses);
    emit totalChanged();
}

void CompteView::initBalances(){
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

    updateValeurBalances(); // set la valeur des balances
}

void CompteView::updateValeurBalances(){
    Compte* c = (Compte*)this->groupe;

    for (int i = 0; i < balances.size(); i++) {
        balances[i]->setValeur(c->getBalance(balances[i]->getUtilisateur()->getEmail()));
    }

    emit balancesChanged(balances);
    emit maxBalanceValueChanged();
}

void CompteView::updateEquilibrage(){
    Compte* c = (Compte*)this->groupe;

    for (int i = 0; i < equilibrages.size(); i++) {
        equilibrages[i]->deleteLater();
    }
    equilibrages.clear();

    // ajout des vues pour les equilibrages
    for (int i = 0; i < c->getEquilibragesSize(); i++) {
        DepenseView* depense = new DepenseView();
        depense->setCompte(this);
        depense->setDepense(c->getEquilibrage(i));
        equilibrages.append(depense);
    }
}

void CompteView::updateAjoutParticipant(){
    GroupeView::updateAjoutParticipant();

    // ajoute une balance pour le nouvel utilisateur
    BalanceView* balance = new BalanceView();
    balance->setUtilisateur(participants[participants.size()-1]);
    balances.append(balance);

    // met a jour les balances
    updateValeurBalances();
    updateEquilibrage();
}


QList<DepenseView*> CompteView::getDepenses() const {
    return depenses;
}

QList<BalanceView*> CompteView::getBalances() const {
    return balances;
}

QList<DepenseView*> CompteView::getEquilibrage(const QString& email) const {
    QList<DepenseView*> e;
    for(int i = 0; i < equilibrages.size(); i++){
        if(equilibrages[i]->getPayeur()->getEmail() == email) e.append(equilibrages[i]);
    }
    return e;
}

QList<DepenseView*> CompteView::getEquilibrageSauf(const QString& email) const {
    QList<DepenseView*> e;
    for(int i = 0; i < equilibrages.size(); i++){
        if(equilibrages[i]->getPayeur()->getEmail() != email) e.append(equilibrages[i]);
    }
    return e;
}

float CompteView::getBalanceValeur(QString utilisateur) {
    for (int i = 0; i < balances.size(); i++) {
        if(balances[i]->getUtilisateur()->getEmail() == utilisateur) return balances[i]->getValeur();
    }
    return 0;
}

float CompteView::getMaxBalanceValue() const {
    float max = 0;
    for (int i = 0; i < balances.size(); i++) {
        if(balances[i]->getValeur() > max) max = balances[i]->getValeur();
        else if(-balances[i]->getValeur() > max) max = -balances[i]->getValeur();
    }
    return max;
}

float CompteView::getTotal() const {
    float balance = 0;
    Compte* compte = (Compte*)this->groupe;

    for (int i = 0; i < compte->getDepensesSize(); i++) {
        if(compte->getDepense(i).getTitre() != "Equilibrage")
            balance += compte->getDepense(i).getMontant();
    }

    return balance;
}
