import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import Classes 1.0


Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("ShareCount")

    Rectangle {
        color: "#efebf2"
        anchors.fill: parent
    }

    GestionnaireInteraction {
        id: gestionnaireInteraction
    }

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "ConnexionPage.qml"
    }

    Loader {
        id: upperLoader
        anchors.fill: parent
        source: ""
    }
}
