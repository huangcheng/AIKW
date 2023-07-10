import QtQuick

Item {
    id: root
    property string active: 'generation'

    FontLoader {
        id: sourceHanSansSCRegular
        source: 'qrc:/fonts/SourceHanSansSC-Regular.otf'
    }

    FontLoader {
        id: sourceHanSansSCBold
        source: 'qrc:/fonts/SourceHanSansSC-Bold.otf'
    }

    Rectangle {
        height: parent.height
        width: parent.width

        color: '#566EF0'

        Text {
            id: logo
            text: "AIKW"
            color: '#FFF'

            font.family: sourceHanSansSCRegular.font.family
            font.bold: sourceHanSansSCBold.font.bold
            font.pixelSize: 24

            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            id: buttonGroup
            height: parent.height

            anchors.left: logo.right
            anchors.leftMargin: 70

            states: [
                State {
                    name: 'generation'
                    when: root.active === 'generation'
                    PropertyChanges {
                        target: generation
                        color: '#FFF'
                    }
                    PropertyChanges {
                        target: generationText
                        color: '#566EF0'
                    }
                },
                State {
                    name: 'configuration'
                    when: root.active === 'configuration'
                    PropertyChanges {
                        target: configuration
                        color: '#FFF'
                    }
                    PropertyChanges {
                        target: configurationText
                        color: '#566EF0'
                    }
                }
            ]

            MouseArea {
                id: generationContainer
                width: 70
                height: parent.height

                onPressed: root.active = 'generation'

                Rectangle {
                    id: generation
                    anchors.fill: parent
                    color: 'transparent'

                    Text {
                        id: generationText
                        text: '生成'

                        color: '#FFF'

                        font.family: sourceHanSansSCRegular.font
                        font.weight: 500
                        font.pixelSize: 14

                        anchors.centerIn: parent
                    }
                }
            }

            MouseArea {
                width: 70
                height: parent.height

                anchors.left: generationContainer.right

                onPressed: root.active = 'configuration'

                Rectangle {
                    id: configuration
                    anchors.fill: parent
                    color: 'transparent'

                    Text {
                        id: configurationText
                        text: '配置'

                        color: '#FFF'

                        font.family: sourceHanSansSCRegular.font
                        font.weight: 500
                        font.pixelSize: 14

                        anchors.centerIn: parent
                    }
                }
            }
        }

        MouseArea {
            height: childrenRect.height
            width: childrenRect.width
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter

            Text {
                text: '开发说明'

                color: '#FFF'

                font.pixelSize: 14
                font.family: sourceHanSansSCRegular.font.family
                font.weight: 400
            }
        }
    }
}
