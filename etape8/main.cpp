/** @mainpage CPOA Documentation etape 8.
 **
 ** Cette partie implémente l'ajout de participant à un groupe ainsi que son interface
 **
 ** Pour lancer le projet:
 ** <ul>
 **     <li>lancez main.cpp</li>
 ** </ul>
 **
 ** Le projet a été testé sur:
 ** <ul>
 **     <li>Windows 10</li>
 **     <li>Arch linux [KDE Plasma]</li>
 ** </ul>
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
