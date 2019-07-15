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
        id: b1
        anchors.top: centerText.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: centerText.horizontalCenter

        text: "Press to update"

        onClicked: {
            Brige.update();
        }
    }

    Button {
        id: b2
        anchors.top: b1.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: centerText.horizontalCenter

        text: "QProcess"

        onClicked: {
            Brige.qprocess();
        }
    }

    Button {
        id: b3
        anchors.top: b2.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: centerText.horizontalCenter

        text: "run App"

        onClicked: {
            Brige.runApp();
        }
    }
}
