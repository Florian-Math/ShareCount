QT       += core gui sql quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GestionnaireInteraction.cpp \
    main.cpp \
    model/Cagnotte.cpp \
    model/Compte.cpp \
    model/DatabaseManager.cpp \
    model/Depense.cpp \
    model/GroupePayement.cpp \
    model/Transfert.cpp \
    model/Utilisateur.cpp \
    view/BalanceView.cpp \
    view/CagnotteView.cpp \
    view/CompteView.cpp \
    view/DepenseView.cpp \
    view/GroupeView.cpp \
    view/TransfertView.cpp \
    view/UtilisateurView.cpp

HEADERS += \
    GestionnaireInteraction.h \
    model/Cagnotte.h \
    model/Compte.h \
    model/DatabaseManager.h \
    model/Depense.h \
    model/GroupePayement.h \
    model/Transfert.h \
    model/Utilisateur.h \
    view/BalanceView.h \
    view/CagnotteView.h \
    view/CompteView.h \
    view/DepenseView.h \
    view/GroupeView.h \
    view/TransfertView.h \
    view/UtilisateurView.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml/qml.qrc
