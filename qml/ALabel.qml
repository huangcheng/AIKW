import QtQuick

Rectangle {
    property alias text: text.text

    color: '#F2F4F5'
    radius: 4

    Text {
        id: text

        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 10
        anchors.left: parent.left
    }
}
