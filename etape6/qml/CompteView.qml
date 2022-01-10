import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: root
    width: 400
    height: 300

    property var groupe: model.modelData

    Rectangle {
        id: rectangle
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
            id: label
            height: 30
            text: qsTr(groupe.titre)
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 10
            font.pointSize: 20
            anchors.leftMargin: 10
            anchors.topMargin: 5
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                gestionnaireInteraction.selectionnerGroupe(index);
                mainLoader.source = "ComptePage.qml";
            }
        }

        Rectangle {
            id: rectangle1
            height: 2
            color: "#000000"
            anchors.left: label.left
            anchors.right: label.right
            anchors.top: label.bottom
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 5
        }

    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}
}
##^##*/
