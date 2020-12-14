import QtQuick 2.0
import QtQuick.Controls.Material 2.12

import StyleSettings 1.0

Rectangle {
    width: ListView.view.width
    height: 50
    color: Material.background
    border.color: Material.primary
    border.width: 2

    Text {
        anchors.fill: parent
        text: model.display
        color: Style.isDarkTheme ? "white" : "black"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: Style.fontSizeMedium
    }
}
