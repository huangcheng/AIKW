import QtQuick
import QtQuick.Layouts

RowLayout {
    property alias description: d.text
    property alias weight: w.text

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
        Layout.preferredWidth: 36
        Layout.preferredHeight: 36
    }
}
