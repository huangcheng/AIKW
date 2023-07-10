import QtQuick
import QtQuick.Layouts

Rectangle {
    property alias title: _title.text
    property alias subTitle: _subTitle.text

    FontLoader {
        id: sourceHanSansSCRegular
        source: 'qrc:/fonts/SourceHanSansSC-Regular.otf'
    }

    FontLoader {
        id: sourceHanSansSCBold
        source: 'qrc:/fonts/SourceHanSansSC-Bold.otf'
    }

    RowLayout {
        id: container
        spacing: 8

        height: 14
        width: parent.width

        Layout.alignment: Qt.AlignHCenter

        Rectangle {
            id: indecator

            color: '#566EF0'

            width: 2
            height: parent.height
            radius: 2
        }

        Text {
            id: _title

            font.family: sourceHanSansSCBold.font.family
            font.bold: sourceHanSansSCBold.font.bold
            font.pixelSize: 14
        }
        Text {
            id: _subTitle

            color: '#7F829F'

            font.family: sourceHanSansSCRegular.font.family
            font.bold: sourceHanSansSCBold.font.bold
            font.pixelSize: 14
        }
    }
}
