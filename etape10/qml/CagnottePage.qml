import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: item1
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
        layer.effect: DropShadow {
            anchors.fill: parent
            radius: 5
            color: "#42000000"
        }


        Rectangle {
            id: rectangle
            color: "#ffffff"
            anchors.fill: parent
        }

        Button {
            id: monCompteButton
            width: 100
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.topMargin: 5
            anchors.rightMargin: 5

            contentItem: Text {
                color: "#000000"
                text: qsTr("Connecté")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
            }

            background: Rectangle {
                color: "#a07ed9"
                radius: 5
                anchors.fill: parent
            }
        }

        Label {
            color: "#000000"
            text: qsTr("Mon ShareCount / " + gestionnaireInteraction.groupeCourant.titre)
            anchors.left: parent.left
            anchors.right: monCompteButton.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 10
            font.bold: false
            anchors.leftMargin: 10
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            font.pointSize: 19
        }
    }


    Item {
        id: leftItem
        anchors.left: parent.left
        anchors.right: parent.horizontalCenter
        anchors.top: buttonBar.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.topMargin: 0
        anchors.bottomMargin: 10
        anchors.leftMargin: 10



        Rectangle {
            id: item2
            color: "#ffffff"
            anchors.fill: parent
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.bottomMargin: 0

            radius: 15
            border.width: 0

            layer.enabled: true;
            layer.effect: DropShadow {
                anchors.fill: parent
                radius: 3
                color: "#42000000"
            }

            ListView {
                id: row
                x: 0
                y: 0
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: total.top
                anchors.bottomMargin: 0

                layer.enabled: true

                model: gestionnaireInteraction.groupeCourant.transferts

                delegate: TransfertView {
                    id: e
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.leftMargin: 0

                    height: 60
                }
            }

            Item {
                id: total
                y: 325
                height: 40
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.bottomMargin: 0

                Label {
                    id: label
                    text: qsTr("Total")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    font.pointSize: 15
                    anchors.leftMargin: 10
                }

                Label {
                    id: label1
                    text: qsTr(Math.round(gestionnaireInteraction.groupeCourant.total * 100) / 100 + " €")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    horizontalAlignment: Text.AlignRight
                    anchors.rightMargin: 10
                    font.pointSize: 15
                }

                Rectangle {
                    id: rectangle1
                    height: 1
                    color: "#2d000000"
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    anchors.rightMargin: 0
                    anchors.leftMargin: 0
                }


            }
        }
    }

    Item {
        id: rightItem
        anchors.left: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: buttonBar.bottom
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 0

        Rectangle {
            id: item3
            color: "#ffffff"
            anchors.fill: parent
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.bottomMargin: 0

            radius: 15
            border.width: 0

            layer.enabled: true;
            layer.effect: DropShadow {
                anchors.fill: parent
                radius: 3
                color: "#42000000"
            }
/*
            ListView {
                id: row2
                anchors.fill: parent

                layer.enabled: true

                model: gestionnaireInteraction.groupeCourant.transferts

                delegate: Item {
                    id: e2
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.leftMargin: 0

                    height: 60
                }
            }*/
        }

    }

    Item {
        id: buttonBar
        height: 55
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: header.bottom
        anchors.topMargin: 0
        anchors.rightMargin: 10
        anchors.leftMargin: 10

        Button {
            id: backButton
            x: 5
            y: 60
            anchors.verticalCenter: parent.verticalCenter

            anchors.left: parent.left
            anchors.leftMargin: 5
            hoverEnabled: true

            background: Rectangle {
                color: backButton.hovered ? "#f6f6f6" : "#ffffff"
                radius: 5

                layer.enabled: true
                layer.effect: DropShadow {
                    anchors.fill: parent
                    radius: 3
                    color: "#25000000"
                }
            }

            contentItem: Text {
                text: qsTr("< Retour")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
            }

            onClicked: mainLoader.source = "MainPage.qml";
        }

        Button {
            id: plusButton
            x: 567
            y: 0
            width: 35
            height: 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: inviteButton.left
            font.pointSize: 15
            anchors.rightMargin: 10

            background: Rectangle {
                color: plusButton.hovered ? "#a57ad9" : "#cb9bf5"
                radius: 20
                anchors.fill: parent

                layer.enabled: true
                layer.effect: DropShadow {
                    anchors.fill: parent
                    radius: 3
                    color: "#25000000"
                }
            }

            contentItem: Image {
                anchors.fill: parent
                source: "images/downArrow.svg"
                smooth: true
                anchors.rightMargin: 7
                anchors.leftMargin: 7
                anchors.bottomMargin: 7
                anchors.topMargin: 7
                fillMode: Image.PreserveAspectCrop
            }

            onClicked: upperLoader.source = "AddTransfertView.qml"
        }

        Button {
            id: infoButton
            x: 567
            y: 0
            width: 35
            height: 35

            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 10


            background: Rectangle {

                color: infoButton.hovered ? "#456aca" : "#6698f3"
                radius: 20
                anchors.fill: parent

                layer.enabled: true
                layer.effect: DropShadow {
                    anchors.fill: parent
                    radius: 3
                    color: "#25000000"
                }
            }

            contentItem: Text {
                color: "#ffffff"
                text: qsTr("i")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
            }

            onClicked: {
                upperLoader.source = "InfoGroupeView.qml"
            }
        }

        Button {
            id: inviteButton
            x: 567
            y: 0
            width: 35
            height: 35
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: infoButton.left
            anchors.rightMargin: 10

            background: Rectangle {
                color: inviteButton.hovered ? "#4ea960" : "#66c570"
                radius: 20
                anchors.fill: parent

                layer.enabled: true
                layer.effect: DropShadow {
                    anchors.fill: parent
                    radius: 3
                    color: "#25000000"
                }
            }

            contentItem: Image {
                anchors.fill: parent
                source: "images/userAdd.svg"
                smooth: true
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
                fillMode: Image.PreserveAspectFit
            }

            onClicked: upperLoader.source = "InviteUtilisateurGroupeView.qml";
        }
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.5;height:480;width:640}
}
##^##*/
