#include "CagnotteView.h"

CagnotteView::CagnotteView(QObject *parent) : GroupeView(parent){

}

void CagnotteView::setGroupe(GroupePayement& groupe) {
    GroupeView::setGroupe(groupe);
}
