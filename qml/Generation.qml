import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Window

ColumnLayout {
    id: root
    spacing: 20

    property double gap: 10

    Layout.fillWidth: true

    ColumnLayout {
        spacing: root.gap

        Layout.fillWidth: true

        Title {
            title: '以图生图'
            subTitle: '( Midjourney上传后的链接)'

            Layout.preferredHeight: 14
        }

        Input {
            placeholder: '图片链接'

            Layout.fillWidth: true
            Layout.preferredHeight: 34
        }
    }

    ColumnLayout {
        spacing: root.gap

        Layout.fillWidth: true

        Title {
            title: '描述'
            Layout.preferredHeight: 14
        }

        InputArea {
            placeholder: '请输入'

            Layout.preferredHeight: 80
            Layout.fillWidth: true
        }
    }

    Component.onCompleted: {
        const { os } = Qt.platform

            if (os === 'windows') {
                root.gap = 20
            }
        }
    }
