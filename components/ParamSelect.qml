import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

RowLayout {
    property alias weight: w.text
    property alias parameter: p.parameter
    signal deleted()

    id: root

    spacing: 10

    Parameter {
        id: p
    }

    Select {
        currentIndex: p.categories.findIndex(({ name }) => name === p.category)
        model: p.categories

        textRole: 'description'
        valueRole: 'name'
        placeholder: '类别'

        Layout.fillWidth: true
        Layout.preferredHeight: 34


        onActivated: (index) => {
                        p.category = p.categories[index].name
                     }
    }

    Select {
        currentIndex: p.parameters.findIndex(({ name }) => name === p.parameter)
        model: p.parameters

        textRole: 'description'
        valueRole: 'name'
        placeholder: '请选择'

        Layout.fillWidth: true
        Layout.preferredHeight: 34

        onActivated: (index) => {
                         p.parameter = p.parameters[index].name
                     }

        onModelChanged: {
            if (model.length > 0 && !parameter) {
                p.parameter = p.parameters[0].name
            }
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
