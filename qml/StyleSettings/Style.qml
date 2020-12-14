pragma Singleton

import QtQuick 2.0
import QtQuick.Controls.Material 2.12

QtObject {
    property bool isDarkTheme: false
    readonly property int theme: isDarkTheme ? Material.Dark : Material.Light

    readonly property int fontSizeBig: 48
    readonly property int fontSizeMedium: 18

    readonly property int marginMedium: 10
}
