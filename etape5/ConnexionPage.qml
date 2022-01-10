import QtQuick 2.0
import QtQuick.Controls 2.0

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
            color: "#13000000"
            radius: 25
            border.width: 0
            anchors.fill: parent
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
                text: qsTr("Se connecter")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: mdp_textfield.bottom
                font.pointSize: 11
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10

                onClicked: {
                    if(gestionnaireInteraction.connexion(email_textfield.text, mdp_textfield.text)) mainLoader.source = "MainPage.qml";
                    else {
                        mainItem.state = "ErrorState";
                        mdp_textfield.text = "";
                    }
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
                text: qsTr("Créer un compte")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: createUser_label.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 3
                font.pointSize: 11

                onClicked: mainLoader.source = "InscriptionPage.qml";
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
    D{i:0;autoSize:true;formeditorZoom:1.33;height:480;width:640}D{i:9}D{i:12}D{i:14}
D{i:1}
}
##^##*/
