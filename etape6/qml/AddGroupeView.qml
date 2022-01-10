import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    width: 400
    height: 300

    //property var groupe: model.modelData

    Rectangle {
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

        Label {
            text: qsTr("+")
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 127
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                upperLoader.source = "CreationGroupeView.qml"
            }
        }
    }

}


