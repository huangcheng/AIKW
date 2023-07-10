import QtQuick
import QtQuick.Window

Window {
    id: window
    width: Screen.desktopAvailableWidth * 0.42
    height: Screen.desktopAvailableHeight * 0.8
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

    Loader {
        id: loader
        source: 'Generation.qml'

        height: window.height - title.height - 40
        width: window.width - 40

        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.left: title.left
        anchors.leftMargin: 20
    }
}
