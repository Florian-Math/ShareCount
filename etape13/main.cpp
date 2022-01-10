/** @mainpage CPOA Documentation etape 13.
 **
 ** Cette partie implémente la suppression d'un groupe
 **
 ** Le projet a été testé sur:
 ** <ul>
 **     <li>Windows 10</li>
 **     <li>Arch linux [KDE Plasma]</li>
 ** </ul>
 **
 ** ================================================================================================
 **
 ** Liste des fonctionnalités par étapes
 **
 ** <table>
 **     <tr>
 **         <th>Etape</th>
 **         <th>Fonctionnalité</th>
 **         <th>Auteur</th>
 **     </tr>
 **
 **     <tr>
 **         <td>1</td>
 **         <td>Connexion & Inscription (Utilisateur)</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>1</td>
 **         <td>Création console simple</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>2</td>
 **         <td>Compte</td>
 **         <td>Fabien & Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>2</td>
 **         <td>Ajout dans la console</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>3</td>
 **         <td>Cagnotte</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>3</td>
 **         <td>Ajout dans la console</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>4</td>
 **         <td>Depense</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>3</td>
 **         <td>Ajout dans la console</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>5</td>
 **         <td>Interface connexion et inscription (étape 1) (voir UtilisateurView)</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>6</td>
 **         <td>Interface création groupe (étape 2 - 3) (voir GroupeView & CompteView & CagnotteView)</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>7</td>
 **         <td>Interface dépenses (étape 4) (voir CompteView & DepenseView)</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>8</td>
 **         <td>Ajout participant groupe (voir GestionnaireInteraction.inviterUtilisateur())</td>
 **         <td>Fabien</td>
 **     </tr>
 **
 **     <tr>
 **         <td>8</td>
 **         <td>Interface ajout participant</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>9</td>
 **         <td>Equilibrage compte (voir Compte.updateEquilibrage())</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>9</td>
 **         <td>Régler équilibrage compte (voir GestionnaireInteraction.reglerDepense())</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>9</td>
 **         <td>Interface équilibrage compte (voir CompteView.updateEquilibrage())</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>10</td>
 **         <td>Transfert compte (voir GestionnaireInteraction.ajouterTransfert())</td>
 **         <td>Fabien & Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>10</td>
 **         <td>Interface transfert cagnotte (voir TransfertView)</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>11</td>
 **         <td>Validation transfert cagnotte (voir GestionnaireInteraction.validerTransfert())</td>
 **         <td>Fabien & Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>11</td>
 **         <td>Interface validation transfert cagnotte</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>12</td>
 **         <td>Déconnexion</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **     <tr>
 **         <td>13</td>
 **         <td>Suppression des groupes</td>
 **         <td>Florian</td>
 **     </tr>
 **
 **
 ** </table>
 **
 **/

#include <QtQuick>
#include "GestionnaireInteraction.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QGuiApplication app(argc, argv);

        qmlRegisterType<GestionnaireInteraction>("Classes", 1, 0, "GestionnaireInteraction");

        QQmlApplicationEngine engine;
        const QUrl url(QStringLiteral("qrc:/main.qml"));

        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
            if(!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
        engine.load(url);

        if (engine.rootObjects().isEmpty())
            return -1;

        return app.exec();
}
