#include "UtilisateurView.h"

#include "GroupeView.h"
#include "CompteView.h"
#include "CagnotteView.h"

UtilisateurView::UtilisateurView(QObject *parent) : QObject(parent)
{

}

UtilisateurView::~UtilisateurView(){
    qDebug() << "DELETE UtilisateurView :" << this;
}

void UtilisateurView::setUtilisateur(Utilisateur& u) {
    utilisateur = &u;
}

void UtilisateurView::updateGroupes() {
    // clear groupes
    qDeleteAll(groupes);
    groupes.clear();

    // ajout des vues pour les groupes
    for (int i = 0; i < utilisateur->getGroupeSize(); i++) {

        if(utilisateur->getGroupe(i)->getType() == "Compte"){
            CompteView* c = new CompteView();
            c->setGroupe(*utilisateur->getGroupe(i));
            groupes.append(c);
        }
        else if(utilisateur->getGroupe(i)->getType() == "Cagnotte"){
            CagnotteView* c = new CagnotteView();
            c->setGroupe(*utilisateur->getGroupe(i));
            groupes.append(c);
        }

    }

    // ajout de l'obj d'ajout (+)
    groupes.append(new GroupeView());

    emit groupesChanged(groupes);
}

GroupeView* UtilisateurView::getGroupe(int i) const {
    return groupes[i];
}

QString UtilisateurView::getEmail() const {
    if(utilisateur == nullptr) return "Null";
    return utilisateur->getEmail();
}

QString UtilisateurView::getNom() const {
    if(utilisateur == nullptr) return "Null";
    return utilisateur->getNom();
}

QString UtilisateurView::getPrenom() const {
    if(utilisateur == nullptr) return "Null";
    return utilisateur->getPrenom();
}

QList<GroupeView*> UtilisateurView::getGroupes() const {
    return groupes;
}


