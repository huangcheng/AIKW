import QtQuick

Rectangle {
    id: root
    FontLoader {
        id: sourceHanSansSCRegular
        source: 'qrc:/fonts/SourceHanSansSC-Regular.otf'
    }

    readonly property string placeholderColor: '#7F829F'
    readonly property string textColor: '#1D2126'

    property alias text: input.text
    property string placeholder: ''

    radius: 4
    height: 34

    color: '#F2F4F5'

    TextInput {
        id: input
        color: textColor
        width: parent.width - 20

        font.family: sourceHanSansSCRegular.font.family
        font.bold: sourceHanSansSCRegular.font.bold
        font.pixelSize: 14

        anchors.centerIn: parent

        Text {
            visible: !input.text
            text: placeholder
            height: parent.height
            color: placeholderColor

            font.family: sourceHanSansSCRegular.font.family
            font.bold: sourceHanSansSCRegular.font.bold
            font.pixelSize: 14

            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
