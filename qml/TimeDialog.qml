import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Dialog {
    id: dialog
    title: qsTr("Set New Time")

    width: 300
    height: 200

    function getTime() {
        let minutes = inputMinutes.text
        while (minutes.length !== 2)
            minutes = '0' + minutes

        let seconds = inputSeconds.text
        while (seconds.length !== 2)
            seconds = '0' + seconds

        let milliseconds = inputMilliseconds.text
        while (milliseconds.length !== 3)
            milliseconds = '0' + milliseconds

        return minutes + ":" + seconds + ":" + milliseconds
    }

    function clear() {
        inputMinutes.text = ""
        inputSeconds.text = ""
        inputMilliseconds.text = ""
    }

    contentItem: Rectangle {
        anchors.fill: parent

        ColumnLayout {
            anchors.fill: parent

            TextField {
                id: inputMinutes
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: TextInput.AlignHCenter
                placeholderText: qsTr("Minutes")
                font.pointSize: 16
                validator: IntValidator {
                    bottom: 0; top: 59;
                }
            }

            TextField {
                id: inputSeconds
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: TextInput.AlignHCenter
                placeholderText: qsTr("Seconds")
                font.pointSize: 16
                validator: IntValidator {
                    bottom: 0; top: 59;
                }
            }

            TextField {
                id: inputMilliseconds
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: TextInput.AlignHCenter
                placeholderText: qsTr("Milliseconds")
                font.pointSize: 16
                validator: IntValidator {
                    bottom: 0; top: 999;
                }
            }

            RowLayout {
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignBottom

                Button {
                    Layout.fillWidth: true
                    Layout.margins: 10
                    text: "Set"
                    onClicked: {
                        dialog.accepted()
                        dialog.close()
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.margins: 10
                    text: "Cancel"
                    onClicked: {
                        dialog.rejected()
                        dialog.close()
                    }
                }
            }
        }
    }
}
