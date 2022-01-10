import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: root
    width: 400
    height: 300

    property var groupe: model.modelData

    Rectangle {
        id: rectangle
        color: mouseArea.containsMouse ? "#f7f4f7" : "#ffffff"
        radius: 5
        anchors.fill: parent
        anchors.topMargin: 0

        layer.enabled: true;
        layer.effect: DropShadow{
            anchors.fill: parent
            radius: 5
            color: "#42000000"
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                gestionnaireInteraction.selectionnerGroupe(index);
                mainLoader.source = "ComptePage.qml";
            }
        }

        Label {
            id: titre
            height: 30
            text: qsTr(groupe.titre)
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 15
            font.pointSize: 20
            anchors.leftMargin: 15
            anchors.topMargin: 5
        }

        Rectangle {
            id: spacer
            height: 2
            color: "#000000"
            anchors.left: titre.left
            anchors.right: titre.right
            anchors.top: titre.bottom
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 5
        }

        Label {
            id: descr
            height: 100
            text: qsTr(groupe.description)
            wrapMode: Label.WordWrap
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: spacer.bottom
            anchors.topMargin: 10
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            font.pointSize: 15
        }

        Label {
            id: participants_label
            text: groupe.participantsSize
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 15
            anchors.bottomMargin: 10
            font.pointSize: 15
        }

        Image {
            id: userIcon
            anchors.left: participants_label.right
            anchors.top: participants_label.top
            anchors.bottom: participants_label.bottom
            source: "images/userIcon.png"
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.leftMargin: 5
            fillMode: Image.PreserveAspectFit
        }

        Label { // "#6dc159" "#c35a5d"
            id: balance_label
            text: "Votre balance : ";
            anchors.right: balance_value.left
            anchors.bottom: parent.bottom
            horizontalAlignment: Text.AlignRight
            anchors.rightMargin: 0
            anchors.bottomMargin: 10
            font.pointSize: 15
        }

        Label {
            id: balance_value
            text: Math.round(groupe.getBalanceValeur(gestionnaireInteraction.utilisateur.email) * 100) / 100 + " €";
            color: groupe.getBalanceValeur(gestionnaireInteraction.utilisateur.email) >= 0 ? "#6dc159" : "#c35a5d"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            horizontalAlignment: Text.AlignRight
            anchors.rightMargin: 15
            anchors.bottomMargin: 10
            font.pointSize: 15
        }



    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}D{i:8}
}
##^##*/
