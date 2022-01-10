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
        height: 207
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
            text: "Inviter utilisateur"
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
            text: "Email :"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titreInfo.bottom
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.topMargin: 20
            font.pointSize: 16
        }

        TextField {
            id: email_textfield
            x: 0
            y: 145
            text: ""
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titreLabel.bottom
            font.pointSize: 10
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.topMargin: 10
            selectByMouse: true

            Keys.onPressed: {
                if(event.key === Qt.Key_Return) invite_button.clicked();
            }
        }

        Label {
            id: error_label
            visible: false
            color: "#d23939"
            text: qsTr("Utilisateur inexistant")
            anchors.left: parent.left
            anchors.top: email_textfield.bottom
            anchors.leftMargin: 20
            anchors.topMargin: 5
        }

        Button {
            id: invite_button
            x: 0
            y: 195
            height: 30
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 15
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            hoverEnabled: true

            onClicked: {
                if(gestionnaireInteraction.inviterUtilisateur(email_textfield.text)) upperLoader.source = ""
                else {
                    mainItem.state = "ErrorState";
                    email_textfield.text = "";
                }
            }

            background: Rectangle {
                color: invite_button.hovered ? "#4ea960" : "#66c570"

                radius: 5
            }

            contentItem: Text {
                anchors.top: parent.top
                color: "#ffffff"
                text: "Inviter"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 6
                font.pointSize: 12
            }
        }

    }
    states: [
        State {
            name: "ErrorState"

            PropertyChanges {
                target: infoGroupeItem
                width: 470
                height: 217
            }

            PropertyChanges {
                target: error_label
                visible: true
            }
        }
    ]

}






/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
