import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    width: 548
    height: 75

    property var transfert: model.modelData


    Item {
        id: rectangle
        anchors.fill: parent

        Image {
            id: transIm
            width: transIm.height
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            source: transfert.montant > 0 ? "images/rightArrow.svg" : "images/leftArrow.svg"
            anchors.leftMargin: 15
            anchors.bottomMargin: 15
            anchors.topMargin: 15
            fillMode: Image.PreserveAspectCrop
        }

        Label {
            id: titreTrans
            text: qsTr(transfert.titre)
            anchors.left: transIm.right
            anchors.top: parent.top
            anchors.leftMargin: 10
            anchors.topMargin: 5
            font.pointSize: 15
        }

        Label {
            id: prixTrans
            x: 404
            width: 139
            height: 29
            text: qsTr(Math.round(transfert.montant * 100) / 100 + " €")
            anchors.right: parent.right
            anchors.top: parent.top
            horizontalAlignment: Text.AlignRight
            anchors.rightMargin: 10
            anchors.topMargin: 5
            font.pointSize: 18
        }

        Label {
            id: payeurTrans
            text: qsTr("déposé par " + transfert.createur.prenom)
            anchors.left: titreTrans.left
            anchors.top: titreTrans.bottom
            anchors.topMargin: 5
            font.pointSize: 10
            anchors.leftMargin: 10
        }

        Rectangle {
            id: spacer
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

/*##^##
Designer {
    D{i:0;formeditorZoom:1.5}
}
##^##*/
