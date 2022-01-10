#include "UtilisateurView.h"

#include "GroupeView.h"

UtilisateurView::UtilisateurView(QObject *parent) : QObject(parent)
{

}

void UtilisateurView::setUtilisateur(Utilisateur& u) {
    utilisateur = &u;

    updateView();
}

void UtilisateurView::updateView(){
    // clear groupes
    for (int i = 0; i < groupes.size(); i++) {
        delete groupes[i];
    }
    groupes.clear();

    // ajout des vues pour les groupes
    for (int i = 0; i < utilisateur->getGroupeSize(); i++) {
        GroupeView* c = new GroupeView();
        c->setGroupe(*utilisateur->getGroupe(i));
        groupes.append(c);
    }

    // ajout de l'obj d'ajout (+)
    groupes.append(new GroupeView());

    emit groupesChanged(groupes);
}

GroupeView* UtilisateurView::getGroupe(int i){
    return groupes[i];
}

QString UtilisateurView::getEmail(){
    if(utilisateur == nullptr) return "Null";
    return utilisateur->getEmail();
}

QList<GroupeView*> UtilisateurView::getGroupes(){
    return groupes;
}


