import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: centerText
        anchors.centerIn: parent
        text: Brige.version()
    }

    Button {
        anchors.top: centerText.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: centerText.horizontalCenter

        text: "Press to update"

        onClicked: {
            Brige.update()
        }
    }
}
