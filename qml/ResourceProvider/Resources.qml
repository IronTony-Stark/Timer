pragma Singleton

import QtQuick 2.0

import StyleSettings 1.0

QtObject {
    readonly property string path: "qrc:/qml/ResourceProvider/resources/"

    readonly property string iconLamp: Style.isDarkTheme ? path + "lamp_white.svg" :
                                                           path + "lamp_black.svg"
}
