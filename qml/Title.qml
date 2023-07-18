import QtQuick
import QtQuick.Layouts

RowLayout {
    property alias title: _title.text
    property alias subTitle: _subTitle.text
    property bool hasAdd: false
    signal added()

    id: container
    spacing: 8

    height: 16
    width: parent.width

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

    Rectangle {
        Layout.preferredWidth: 1024
        Layout.fillWidth: true

        MouseArea {
            width: 16
            height: 16

            visible: hasAdd

            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter

            Image {
                source: '/images/PlusCircleF.svg'

                anchors.fill: parent
            }

            onPressed: added()
        }
    }
}
