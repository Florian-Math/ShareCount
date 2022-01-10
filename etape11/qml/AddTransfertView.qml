import QtQuick 2.0
import QtQuick.Controls 1.4
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
        height: 295
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
            text: "Déposer argent"
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.topMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            id: titreLabel
            text: "Titre :"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titreInfo.bottom
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.topMargin: 20
            font.pointSize: 16
        }

        TextField {
            id: titre_textfield
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


        }


        Label {
            id: montantLabel
            text: "Montant :"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titre_textfield.bottom
            anchors.rightMargin: 20
            font.pointSize: 16
            anchors.topMargin: 10
            anchors.leftMargin: 20
        }

        TextField {
            id: montant_textfield
            x: 0
            y: 150
            text: ""
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: montantLabel.bottom
            anchors.rightMargin: 20
            font.pointSize: 10
            anchors.topMargin: 10
            anchors.leftMargin: 20
            selectByMouse: true

            validator: RegExpValidator { regExp: /[0-9]+[.][0-9]{2}/ }

            Keys.onPressed: {
                if(event.key === Qt.Key_Return) createTransfert_button.clicked();
            }
        }

        Label {
            id: error_label
            visible: false
            color: "#d23939"
            text: qsTr("Informations erronées")
            anchors.left: parent.left
            anchors.top: montant_textfield.bottom
            anchors.leftMargin: 20
            anchors.topMargin: 10
        }

        Button {
            id: createTransfert_button
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
                if(gestionnaireInteraction.ajouterTransfert(titre_textfield.text, montant_textfield.text)) {
                    upperLoader.source = "";
                }else{
                    mainItem.state = "ErrorState";
                    titre_textfield.text = "";
                }
            }

            background: Rectangle {
                color: createTransfert_button.hovered ? "#a57ad9" : "#cb9bf5"

                radius: 5
            }

            contentItem: Text {
                anchors.top: parent.top
                color: "#ffffff"
                text: "Effectuer transfert"
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
                target: error_label
                visible: true
            }

            PropertyChanges {
                target: infoGroupeItem
                width: 470
                height: 309
            }
        }
    ]

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
