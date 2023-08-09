import QtQuick
import QtQuick.Layouts

import components

RowLayout {
    property alias description: d.text
    property alias weight: w.text
    signal deleted()

    spacing: 10

    Input {
        id: d

        placeholder: '请输入'

        Layout.fillWidth: true
    }

    Input {
        id: w

        placeholder: '权重'

        Layout.preferredWidth: 50
    }

    MouseArea {
        id: button

        hoverEnabled: true

        Layout.preferredWidth: 36
        Layout.preferredHeight: 36

        onPressed: deleted()

        Rectangle {
            anchors.fill: parent

            color: '#F2F4F5'

            Image {
                source: button.containsMouse ? '/images/TrashHover.svg' : '/images/Trash.svg'

                width: 20
                height: 20

                anchors.centerIn: parent
            }
        }
    }
}
