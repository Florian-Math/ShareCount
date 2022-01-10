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
        id: selectionTypeGroupeItem
        width: 470
        height: 286
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
            verticalAlignment: Text.AlignBottom
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

        Rectangle {
            id: rectangle2
            y: 28
            width: 200
            height: 200
            radius: 5

            color: mouseAreaCompte.containsMouse ? "#f7f4f7" : "#ffffff"
            border.color: "#1b000000"
            border.width: 2

            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.leftMargin: 20

            Label {
                id: label
                y: 170
                height: 30
                text: qsTr("Compte")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                font.pointSize: 20
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.bottomMargin: 5
            }

            MouseArea {
                id: mouseAreaCompte
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    creationGroupeItem.type = "Compte";
                    selectionTypeGroupeItem.visible = false;
                    creationGroupeItem.visible = true;
                }
            }
        }

        Rectangle {
            id: rectangle3
            x: 232
            y: 28
            width: 200
            height: 200
            radius: 5

            color: mouseAreaCagn.containsMouse ? "#f7f4f7" : "#ffffff"
            border.color: "#1b000000"
            border.width: 2

            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.rightMargin: 20

            Label {
                id: label1
                y: 170
                height: 30
                text: qsTr("Cagnotte")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                anchors.bottomMargin: 5
                anchors.leftMargin: 0
                font.pointSize: 20
                anchors.rightMargin: 0
            }

            MouseArea {
                id: mouseAreaCagn
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    creationGroupeItem.type = "Cagnotte";
                    selectionTypeGroupeItem.visible = false;
                    creationGroupeItem.visible = true;
                }
            }
        }

        Label {
            id: label2
            width: 252
            height: 37
            text: qsTr("Créer un groupe")
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.topMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }

    Rectangle {
        id: creationGroupeItem

        property string type: "Empty"

        width: 429
        height: 346
        visible: false
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
            color: quitCross2.containsMouse ? "#48000000" : "#18000000"
            text: qsTr("🗙")
            anchors.right: parent.right
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignBottom
            font.pointSize: 20
            anchors.topMargin: 10
            anchors.rightMargin: 8

            MouseArea {
                id: quitCross2
                anchors.fill: parent
                onClicked: upperLoader.source = ""
                hoverEnabled: true
            }
        }

        Label {
            id: titreSection
            width: 252
            height: 37
            text: qsTr("Créer un " + creationGroupeItem.type)
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.topMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Item {
            id: item2
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titreSection.bottom
            anchors.bottom: parent.bottom
            anchors.topMargin: 30
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            anchors.bottomMargin: 10

            Label {
                id: titre_label
                x: 0
                text: qsTr("Titre")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                font.pointSize: 14
            }

            TextField {
                id: titre_textfield
                x: 0
                visible: true
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: titre_label.bottom
                font.pointSize: 10
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                placeholderText: qsTr("")
                selectByMouse: true


            }

            Label {
                id: descr_label
                x: 0
                text: qsTr("Description")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: titre_textfield.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.topMargin: 10
                font.pointSize: 14
            }

            TextField {
                id: descr_textfield
                x: 0
                height: 111
                text: ""
                wrapMode: Label.WordWrap
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: descr_label.bottom
                verticalAlignment: Text.AlignTop
                font.pointSize: 10
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                selectByMouse: true

                Keys.onPressed: {
                    if(event.key === Qt.Key_Return) creation_button.clicked();
                }
            }

            Label {
                id: error_label
                visible: false
                color: "#d23939"
                text: qsTr("Informations erronées")
                anchors.top: descr_textfield.bottom
                anchors.topMargin: 5
            }

            Button {
                id: creation_button
                x: 0
                height: 30
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: descr_textfield.bottom
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 10

                onClicked: {
                    var res = false;
                    switch(creationGroupeItem.type){
                    case "Compte":
                        res = gestionnaireInteraction.creerCompte(titre_textfield.text, descr_textfield.text);
                        break;
                    case "Cagnotte":
                        res = gestionnaireInteraction.creerCagnotte(titre_textfield.text, descr_textfield.text);
                        break;
                    }

                    if(res) upperLoader.source = "";
                    else mainItem.state = "ErrorState";
                }
                hoverEnabled: true

                background: Rectangle {
                    color: creation_button.hovered ? "#a57ad9" : "#cb9bf5"
                    radius: 5
                }

                contentItem: Text {
                    text: qsTr("Créer " + creationGroupeItem.type)
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
                target: error_label
                visible: true
            }

            PropertyChanges {
                target: creation_button
                anchors.topMargin: 25
            }

            PropertyChanges {
                target: creationGroupeItem
                width: 429
                height: 363
            }
        }
    ]



}


/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.1;height:480;width:640}
}
##^##*/
