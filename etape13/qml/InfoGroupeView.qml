import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: mainItem
    Rectangle {
        id: rectangle
        color: "#76000000"
        anchors.fill: parent

        MouseArea {
            anchors.fill: parent
            onClicked: upperLoader.source = ""
        }
    }

    Rectangle {
        id: infoGroupeItem
        width: 470
        height: 421
        color: "#ffffff"
        radius: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true

        MouseArea {
            anchors.fill: parent
        }

        Label {
            x: 432
            width: 30
            height: 30
            color: quitCross.containsMouse ? "#48000000" : "#18000000"
            text: qsTr("🗙")
            anchors.right: parent.right
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.topMargin: 10
            anchors.rightMargin: 8

            MouseArea {
                id: quitCross
                anchors.fill: parent
                onClicked: upperLoader.source = ""
                hoverEnabled: true
            }
        }

        Label {
            id: titreInfo
            width: 252
            height: 37
            text: qsTr("Informations " + gestionnaireInteraction.groupeCourant.type)
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.topMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            id: titreLabel
            height: 25
            text: qsTr("Titre : " + gestionnaireInteraction.groupeCourant.titre)
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titreInfo.bottom
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.topMargin: 20
            font.pointSize: 16
        }

        Label {
            id: descrLabel
            height: 75
            text: qsTr("Description : " + gestionnaireInteraction.groupeCourant.description)
            wrapMode: Label.WordWrap
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titreLabel.bottom
            anchors.rightMargin: 20
            font.pointSize: 16
            anchors.leftMargin: 20
            anchors.topMargin: 10
        }

        Label {
            id: participantLabel
            height: 25
            text: "Participants :"
            anchors.left: parent.left
            anchors.top: descrLabel.bottom
            font.pointSize: 16
            anchors.leftMargin: 20
            anchors.topMargin: 10
        }

        ListView {
            id: listView
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: participantLabel.bottom
            anchors.bottom: clore_button.top
            anchors.bottomMargin: 10
            anchors.rightMargin: 30
            anchors.leftMargin: 30
            anchors.topMargin: 10

            layer.enabled: true

            model: gestionnaireInteraction.groupeCourant.participants

            delegate: Item {
                property var participant: model.modelData

                height: 20
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 111
                anchors.leftMargin: 0

                Label {
                    text: qsTr(participant.prenom + " " + participant.nom + " (" + participant.email + ")");
                    font.pointSize: 12
                }

            }
        }

        Rectangle {
            id: addButton
            width: 30
            height: 30
            color: addButtonMouseArea.containsMouse ? "#4ea960" : "#66c570"
            radius: 15
            border.width: 0
            anchors.verticalCenter: participantLabel.verticalCenter
            anchors.left: participantLabel.right
            anchors.leftMargin: 10

            Label {
                id: label
                color: "#ffffff"
                text: qsTr("+")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignTop
                font.pointSize: 18
            }

            MouseArea {
                id: addButtonMouseArea
                anchors.fill: parent
                hoverEnabled: true

                onClicked: upperLoader.source = "InviteUtilisateurGroupeView.qml";
            }
        }

        Button {
            id: clore_button
            x: 0
            y: 195
            height: 30
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            hoverEnabled: true

            onClicked: {
                if(gestionnaireInteraction.cloreGroupe()) {
                    upperLoader.source = "";
                    mainLoader.source = "MainPage.qml";

                }
            }

            background: Rectangle {
                color: clore_button.hovered ? "#b14251" : "#e1665f"

                radius: 5
            }

            contentItem: Text {
                text: qsTr("Clore " + gestionnaireInteraction.groupeCourant.type)
                anchors.top: parent.top
                color: "#ffffff"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 6
                font.pointSize: 12
            }
        }

    }

}




/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.1;height:480;width:640}
}
##^##*/
