import QtQuick
import QtQuick.Layouts

Rectangle {
    property alias title: _title.text
    property alias subTitle: _subTitle.text

    RowLayout {
        id: container
        spacing: 8

        height: 14
        width: parent.width

        Layout.alignment: Qt.AlignHCenter

        FontLoader {
            id: font
        }

        Rectangle {
            id: indecator

            color: '#566EF0'

            width: 2
            height: parent.height
            radius: 2
        }

        Text {
            id: _title
        }
        Text {
            id: _subTitle

            color: '#7F829F'
        }
    }
}
