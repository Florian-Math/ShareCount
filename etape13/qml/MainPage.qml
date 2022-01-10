import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: root

    GridView {
        id: gridView
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.topMargin: 10
        model: gestionnaireInteraction.utilisateur.groupes
/*
        delegate: CompteView {
            width: 400
            height: 300
        }
*/
        delegate: Loader {
            width: 400
            height: 300
            property var groupe: model.modelData
            source: switch(groupe.type){
                    case "Empty": return "AddGroupeView.qml";
                    case "Compte": return "CompteView.qml";
                    case "Cagnotte": return "CagnotteView.qml";
                    default: return "AddGroupeView.qml";
            }
        }

        cellWidth: 400 + 10
        cellHeight: 300 + 10

        anchors.rightMargin: Math.round((root.width - (Math.floor(root.width / cellWidth) * cellWidth) )/2) -1
        anchors.leftMargin: Math.round((root.width - (Math.floor(root.width / cellWidth) * cellWidth) )/2) -1
    }


    Item {
        id: header
        height: 50
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        layer.enabled: true;
        layer.effect: DropShadow{
            anchors.fill: parent
            verticalOffset: 2
            radius: 5
            color: "#42000000"
        }


        Rectangle {
            id: rectangle
            color: "#ffffff"
            anchors.fill: parent
        }

        Button {
            width: 100
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.topMargin: 5
            anchors.rightMargin: 5

            contentItem: Text {
                color: "#a07ed9"
                text: qsTr("(Déconnexion)")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.underline: true
                font.pointSize: 10
            }

            background: Rectangle {
                color: "#00a07ed9"
                radius: 5
                anchors.fill: parent
            }

            onClicked: {
                gestionnaireInteraction.deconnexion();
                mainLoader.source = "ConnexionPage.qml"
            }
        }

        Label {
            id: label
            color: "#000000"
            text: qsTr("Mon ShareCount")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.bold: false
            anchors.leftMargin: 10
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            font.pointSize: 19
        }
    }




}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.25;height:480;width:640}
}
##^##*/
