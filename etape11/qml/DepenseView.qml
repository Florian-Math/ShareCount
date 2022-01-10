import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    width: 548
    height: 75

    property var depense: model.modelData


    Item {
        id: rectangle
        anchors.fill: parent

        Label {
            id: titreDep
            text: qsTr(depense.titre)
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 10
            anchors.topMargin: 5
            font.pointSize: 15
        }

        Label {
            id: prixDep
            x: 404
            width: 139
            height: 29
            text: qsTr(Math.round(depense.montant * 100) / 100 + " €")
            anchors.right: parent.right
            anchors.top: parent.top
            horizontalAlignment: Text.AlignRight
            anchors.rightMargin: 10
            anchors.topMargin: 5
            font.pointSize: 18
        }

        Label {
            id: payeurDep
            text: qsTr("payé par " + depense.payeur.prenom)
            anchors.left: parent.left
            anchors.top: titreDep.bottom
            anchors.topMargin: 5
            font.pointSize: 10
            anchors.leftMargin: 20
        }

        Rectangle {
            id: rectangle1
            height: 1
            color: "#33000000"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.rightMargin: 10
            anchors.leftMargin: 10
        }
    }

}
