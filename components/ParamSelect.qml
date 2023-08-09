import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

RowLayout {
    property alias weight: w.text
    signal deleted()
    signal parameterChanged(param: string)

    id: root

    spacing: 10

    Parameter {
        id: parameter
    }

    ComboBox {
        currentIndex: -1
        model: parameter.categories

        textRole: 'description'
        valueRole: 'name'

        onActivated: (index) => {
                        parameter.category = parameter.categories[index].name
                     }
    }

    ComboBox {
        currentIndex: -1
        model: parameter.parameters

        textRole: 'description'
        valueRole: 'name'

        Layout.fillWidth: true

        onActivated: (index) => {
                         const param = parameter.parameters[index].name

                         parameterChanged(param)
                     }
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
