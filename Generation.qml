import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ColumnLayout {
    spacing: 20

    Layout.fillWidth: true

    FontLoader {
        id: sourceHanSansSCRegular
        source: 'qrc:/fonts/SourceHanSansSC-Regular.otf'
    }

    FontLoader {
        id: sourceHanSansSCBold
        source: 'qrc:/fonts/SourceHanSansSC-Bold.otf'
    }

    ColumnLayout {
        spacing: 10

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
}
