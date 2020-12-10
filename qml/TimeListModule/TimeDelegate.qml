import QtQuick 2.0

Rectangle {
    width: ListView.view.width
    height: 50
    border.color: "black"
    border.width: 2
    Text {
        width: parent.width
        text: model.display
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 18
    }
}
