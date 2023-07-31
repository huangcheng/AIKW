import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Window

ColumnLayout {
    id: root
    spacing: 20

    property double gap: 10

    ColumnLayout {
        spacing: root.gap

        Title {
            title: '以图生图'
            subTitle: '( Midjourney上传后的链接)'

            Layout.preferredHeight: 14
            Layout.fillWidth: true
        }

        Input {
            placeholder: '图片链接'
            text: generation.url ?? ''

            onTextChanged: {
                generation.url = text
            }

            Layout.fillWidth: true
            Layout.preferredHeight: 34
        }
    }

    ColumnLayout {
        spacing: root.gap

        Title {
            title: '描述'

            Layout.preferredHeight: 14
            Layout.fillWidth: true
        }

        InputArea {
            placeholder: '请输入'

            text: generation.description ?? ''

            onTextChanged: {
                generation.description = text
            }

            Layout.preferredHeight: 80
            Layout.fillWidth: true
        }
    }


    ColumnLayout {
        spacing: root.gap

        Title {
            title: '描述 (权重)'

            Layout.preferredHeight: 14
            Layout.fillWidth: true

            hasAdd: true
            onAdded: {
            }
        }
    }

    Component.onCompleted: {
        const { os } = Qt.platform

        if (os === 'windows') {
            root.gap = 20
        }
    }
}
