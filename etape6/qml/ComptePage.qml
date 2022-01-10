import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: item1

    Label {
        id: label
        x: 51
        y: 17
        text: qsTr(gestionnaireInteraction.groupeCourant.titre)
    }

    Button {
        id: button
        width: 35
        height: 20
        text: qsTr("<")
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 10
        anchors.topMargin: 10

        onClicked: {
            mainLoader.source = "MainPage.qml";
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
