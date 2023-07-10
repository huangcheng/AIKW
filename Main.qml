import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: window
    width: Screen.desktopAvailableWidth * 0.6
    height: Screen.desktopAvailableHeight * 0.74
    visible: true
    title: qsTr('AIKW')

    property string selected: 'generation'

    TitleBar {
        id: title
        height: 40
        width: parent.width

        onActiveChanged: {
            if (active === 'generation') {
                loader.source = 'Generation.qml'
            } else {
                loader.source = 'Configuration.qml'
            }
        }
    }

    ScrollView {
        height: window.height - title.height - 40
        width: window.width - 40
        clip: true

        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.left: title.left
        anchors.leftMargin: 20

        Loader {
            id: loader
            source: 'Generation.qml'

            width: parent.width

            anchors.top: parent.top
            anchors.left: parent.left
        }
    }
}
