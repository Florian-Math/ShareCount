#include "BalanceView.h"

BalanceView::BalanceView(QObject *parent) : QObject(parent)
{

}

BalanceView::BalanceView(UtilisateurView* u)  : QObject() {
    this->utilisateur = u;
}

void BalanceView::setValeur(float v) {
    this->valeur = v;

    emit valeurChanged();
}

void BalanceView::addValeur(float v) {
    this->valeur += v;

    emit valeurChanged();
}

void BalanceView::setUtilisateur(UtilisateurView* u){
    utilisateur = u;
}

UtilisateurView* BalanceView::getUtilisateur(){
    return utilisateur;
}

float BalanceView::getValeur(){
    return valeur;
}
