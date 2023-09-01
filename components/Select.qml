import QtQuick
import QtQuick.Controls

Item {
    property alias model: combo.model
    property alias currentIndex: combo.currentIndex
    property alias textRole: combo.textRole
    property alias valueRole: combo.valueRole

    property string placeholder: ""

    signal activated(int index)

    ComboBox {
        id: combo

        background: Rectangle {
            border.width: 0
            radius: 4
            color: '#F2F4F5'
        }

        indicator: Image {
            id: image
            x: combo.width - width - combo.rightPadding
            y: combo.topPadding + (combo.availableHeight - height) / 2
            width: 14
            height: 14
            source: '/images/Down.svg'

            states: State {
                name: 'up'
                when: combo.down
                PropertyChanges {
                    target: image
                    rotation: -180
                }
            }

            transitions: Transition {
                RotationAnimation {
                    duration: 100
                    direction: RotationAnimation.Counterclockwise
                }
            }
        }

        anchors.fill: parent

        onActivated: index => {
                         parent.activated(index)
                     }
    }

    Text {
        visible: combo.currentIndex === -1
        text: placeholder
        height: parent.height
        color: '#7F829F'

        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 4
    }
}
