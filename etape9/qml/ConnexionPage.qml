import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item{
    id: mainItem

    Item {
        id: connexionItem
        x: 22
        y: 24
        width: 383
        height: 328
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle {
            id: cbg
            color: "#ffffff"
            radius: 25
            border.width: 0
            anchors.fill: parent

            layer.enabled: true;
            layer.effect: DropShadow{
                anchors.fill: parent
                //verticalOffset: 3
                radius: 5
                color: "#42000000"
            }
        }

        Item {
            id: item2
            anchors.fill: parent
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 10
            anchors.topMargin: 10

            Label {
                id: title
                x: 0
                y: 0
                text: qsTr("Connexion")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                horizontalAlignment: Text.AlignHCenter
                font.underline: false
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                font.pointSize: 18
            }

            Label {
                id: email_label
                x: 0
                y: 49
                text: qsTr("E-mail")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: title.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 20
                font.pointSize: 14
            }

            TextField {
                id: email_textfield
                x: 0
                y: 72
                visible: true
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: email_label.bottom
                font.pointSize: 10
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                placeholderText: qsTr("")
                selectByMouse: true


            }

            Label {
                id: mdp_label
                x: 0
                y: 122
                text: qsTr("Mot de passe")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: email_textfield.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.topMargin: 10
                font.pointSize: 14
            }

            TextField {
                id: mdp_textfield
                x: 0
                y: 145
                text: ""
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: mdp_label.bottom
                font.pointSize: 10
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                placeholderText: qsTr("")
                selectByMouse: true
                echoMode: TextInput.Password

                Keys.onPressed: {
                    if(event.key === Qt.Key_Return) connexion_button.clicked();
                }
            }

            Label {
                id: error_label
                visible: false
                color: "#d23939"
                text: qsTr("E-mail ou mot de passe erroné")
                anchors.left: parent.left
                anchors.top: mdp_textfield.bottom
                anchors.leftMargin: 10
                anchors.topMargin: 5
            }

            Button {
                id: connexion_button
                x: 0
                y: 195
                height: 30
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: mdp_textfield.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10
                hoverEnabled: true

                onClicked: {
                    if(gestionnaireInteraction.connexion(email_textfield.text, mdp_textfield.text)) mainLoader.source = "MainPage.qml";
                    else {
                        mainItem.state = "ErrorState";
                        mdp_textfield.text = "";
                    }
                }

                background: Rectangle {
                    color: connexion_button.hovered ? "#a57ad9" : "#cb9bf5"
                    radius: 5
                }

                contentItem: Text {
                    text: qsTr("Se connecter")
                    anchors.fill: parent
                    color: "#ffffff"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 12
                }
            }

            Rectangle {
                id: sep
                height: 2
                color: "#7a000000"
                radius: 1
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: connexion_button.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10
            }

            Label {
                id: createUser_label
                x: 116
                y: 280
                width: 155
                height: 25
                text: qsTr("Pas de compte ?")
                anchors.top: sep.bottom
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 5
                font.pointSize: 12
            }

            Button {
                id: createUser_button
                y: 308
                height: 30
                visible: true
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: createUser_label.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 3
                hoverEnabled: true

                onClicked: mainLoader.source = "InscriptionPage.qml";

                background: Rectangle {
                    color: createUser_button.hovered ? "#775db5" : "#a07ed9"
                    radius: 5
                }

                contentItem: Text {
                    text: qsTr("Créer un compte")
                    anchors.fill: parent
                    color: "#ffffff"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 12
                }
            }
        }

    }
    states: [
        State {
            name: "ErrorState"

            PropertyChanges {
                target: connexion_button
                anchors.topMargin: 25
            }

            PropertyChanges {
                target: error_label
                visible: true
            }

            PropertyChanges {
                target: connexionItem
                height: 340
            }

        }
    ]
}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.33;height:480;width:640}
}
##^##*/
