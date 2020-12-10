import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.2

import TimeListModule 1.0

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Iron Timer")

    FileDialog {
        id: fileDialog
        title: qsTr("Please choose a file")
        folder: shortcuts.home
        nameFilters: "*.wav"
        onAccepted: {
            timer.setAlarmSound(fileDialog.fileUrl)
        }
    }

    TimeDialog {
        id: timeDialog
        onAccepted: {
            timer.setInitialTime(timeDialog.getTime())
        }
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

        TimeList {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            model: timeListModel
        }

        GridLayout {
            columns: parent.width > 600 ? 2 : 1
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignBottom

            Button {
                Layout.fillWidth: true
                Layout.margins: 10
                Layout.columnSpan: parent.columns

                text: timer.isActive ? qsTr("Pause") : qsTr("Start")
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
                text: qsTr("Tap")
                font.pointSize: 18
                onClicked: {
                    timer.tap()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: !timer.isActive
                text: qsTr("Reset")
                font.pointSize: 18
                onClicked: {
                    timer.reset()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: !timer.isActive
                text: qsTr("Set Initial Time")
                font.pointSize: 18
                onClicked: {
                    timeDialog.clear()
                    timeDialog.open()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: 10

                enabled: !timer.isActive
                text: qsTr("Set Timeout Sound")
                font.pointSize: 18
                onClicked: {
                    fileDialog.open()
                }
            }
        }
    }
}
