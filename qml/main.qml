import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.12

import TimeListModule 1.0
import StyleSettings 1.0
import ResourceProvider 1.0

ApplicationWindow {

    readonly property int resizeThreshold: 600

    minimumWidth: 380
    width: 480
    height: 640
    visible: true
    title: qsTr("Iron Timer")

    Material.theme: Style.theme
    Material.accent: Material.Red
    Material.primary: Material.Green

    Image {
        visible: parent.width > 470
        width: Math.min(parent.width / 10, 64)
        height: width
        mipmap: true
        scale:  mouseArea.containsMouse ? 1.2 : 1.0
        source: Resources.iconLamp

        anchors {
            right: parent.right
            top: parent.top
            margins: Style.marginMedium
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                Style.isDarkTheme = !Style.isDarkTheme
            }
        }
    }

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
            font.pointSize: Style.fontSizeBig
            color: Material.accent
        }

        TimeList {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: Style.marginMedium
            Layout.rightMargin: Style.marginMedium
            model: timeListModel
        }

        GridLayout {
            columns: parent.width > resizeThreshold ? 2 : 1
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignBottom

            Button {
                Layout.fillWidth: true
                Layout.margins: Style.marginMedium
                Layout.columnSpan: parent.columns

                text: timer.isActive ? qsTr("Pause") : qsTr("Start")
                Material.foreground: "white"
                Material.background: timer.isActive ? Material.accent : Material.primary
                font.pointSize: Style.fontSizeMedium
                onReleased: {
                    if (timer.isActive)
                        timer.pause()
                    else
                        timer.start()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: Style.marginMedium

                enabled: timer.isActive
                text: qsTr("Tap")
                font.pointSize: Style.fontSizeMedium
                onReleased: {
                    timer.tap()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: Style.marginMedium

                enabled: !timer.isActive
                text: qsTr("Reset")
                font.pointSize: Style.fontSizeMedium
                onClicked: {
                    timer.reset()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: Style.marginMedium

                enabled: !timer.isActive
                text: qsTr("Set Initial Time")
                font.pointSize: Style.fontSizeMedium
                onClicked: {
                    timeDialog.clear()
                    timeDialog.open()
                }
            }

            Button {
                Layout.fillWidth: true
                Layout.margins: Style.marginMedium

                enabled: !timer.isActive
                text: qsTr("Set Timeout Sound")
                font.pointSize: Style.fontSizeMedium
                onClicked: {
                    fileDialog.open()
                }
            }
        }
    }
}
