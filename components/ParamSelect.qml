import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

RowLayout {
    id: root

    spacing: 10

    Parameter {
        id: parameter
    }

    ComboBox {
        model: parameter.categories

        textRole: 'description'
        valueRole: 'name'

        Layout.fillWidth: true

        onActivated: (index) => {
                        parameter.category = parameter.categories[index].name
                     }
    }

    ComboBox {
        model: parameter.parameters

        textRole: 'description'
        valueRole: 'name'

        Layout.fillWidth: true
    }

    Input {
        id: w

        placeholder: '权重'

        Layout.preferredWidth: 50
    }
}
