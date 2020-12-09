import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import com.irontony.timer 1.0

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Iron Timer")

    Timer {
        id: timer
    }

    ColumnLayout {
        anchors.fill: parent

        Text {
            id: textTime
            Layout.alignment: Qt.AlignHCenter

            text: timer.timeOnTimer
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

                text: timer.isActive ? "Pause" : "Start"
                font.pointSize: 18
                onClicked: {
                    if (timer.isActive)
                        timer.pause()
                    else
                        timer.start()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: timer.isActive
                text: "Tap"
                font.pointSize: 18
                onClicked: {
                    timer.tap()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: !timer.isActive
                text: "Reset"
                font.pointSize: 18
                onClicked: {
                    timer.reset()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: !timer.isActive
                text: "Set Initial Time"
                font.pointSize: 18
                onClicked: {

                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: !timer.isActive
                text: "Set Timeout Sound"
                font.pointSize: 18
                onClicked: {

                }
            }
        }
    }
}
