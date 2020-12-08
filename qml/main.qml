import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Iron Timer")

    ColumnLayout {
        anchors.fill: parent

        Text {
            id: textTime
            Layout.alignment: Qt.AlignHCenter

            text: qsTr("00:00:00")
            font.pointSize: 48
            color: "#dc143c"
        }

        GridLayout {
            columns: parent.width > 600 ? 2 : 1
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignBottom

            Button {
                Layout.fillWidth: true
                Layout.margins: 10
                Layout.columnSpan: parent.columns

                text: "Start"
                font.pointSize: 18
                onClicked: {
                    console.log("Start Clicked")
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                text: "Tap"
                font.pointSize: 18
                onClicked: {
                    console.log("Tap Clicked")
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                text: "Reset"
                font.pointSize: 18
                onClicked: {
                    console.log("Reset Clicked")
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                text: "Set Initial Time"
                font.pointSize: 18
                onClicked: {
                    console.log("Set Initial Time Clicked")
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                text: "Set Timeout Sound"
                font.pointSize: 18
                onClicked: {
                    console.log("Set Timeout Sound Clicked")
                }
            }
        }
    }
}
