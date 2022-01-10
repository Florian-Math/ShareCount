import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: mainItem

    Item {
        id: inscriptionItem
        x: 22
        y: 24
        width: 383
        height: 399
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
                text: qsTr("Inscription")
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
                id: nom_label
                x: 0
                y: 49
                text: qsTr("Nom")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: email_textfield.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10
                font.pointSize: 14
            }

            TextField {
                id: nom_textfield
                x: 0
                y: 72
                visible: true
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: nom_label.bottom
                font.pointSize: 10
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                placeholderText: qsTr("")
                selectByMouse: true
            }

            Label {
                id: prenom_label
                x: 0
                y: 49
                text: qsTr("Prenom")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: nom_textfield.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10
                font.pointSize: 14
            }

            TextField {
                id: prenom_textfield
                x: 0
                y: 72
                visible: true
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: prenom_label.bottom
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
                anchors.top: prenom_textfield.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.topMargin: 10
                font.pointSize: 14
            }

            TextField {
                id: mdp_textfield
                x: 0
                y: 145
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
                    if(event.key === Qt.Key_Return) inscription_button.clicked();
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
                id: inscription_button
                x: 0
                y: 195
                height: 30
                text: qsTr("S'inscrire")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: mdp_textfield.bottom
                font.pointSize: 11
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10

                onClicked: {
                    if(gestionnaireInteraction.inscription(email_textfield.text, nom_textfield.text, prenom_textfield.text, mdp_textfield.text)) mainLoader.source = "MainPage.qml";
                    else {
                        mainItem.state = "ErrorState";
                        mdp_textfield.text = "";
                    }
                }
            }
        }

    }
    states: [
        State {
            name: "ErrorState"

            PropertyChanges {
                target: inscription_button
                anchors.topMargin: 25
            }

            PropertyChanges {
                target: error_label
                visible: true
                text: qsTr("Informations erronées ou non complètes")
            }

            PropertyChanges {
                target: inscriptionItem
                height: 418
            }

        }
    ]
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.33;height:480;width:640}
}
##^##*/
