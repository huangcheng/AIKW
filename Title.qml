import QtQuick

Item {
    id: root
    property string selected: 'generate'
    signal selectedChange(selected: string)

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
                    name: 'generate'
                    when: root.selected === 'generate'
                    PropertyChanges {
                        target: generate
                        color: '#FFF'
                    }
                    PropertyChanges {
                        target: generateText
                        color: '#566EF0'
                    }
                },
                State {
                    name: 'config'
                    when: root.selected === 'config'
                    PropertyChanges {
                        target: config
                        color: '#FFF'
                    }
                    PropertyChanges {
                        target: configText
                        color: '#566EF0'
                    }
                }
            ]

            MouseArea {
                id: generateContainer
                width: 70
                height: parent.height

                onPressed: {
                    const selected = 'generate'

                    root.selected = selected
                    root.selectedChange(selected)
                }

                Rectangle {
                    id: generate
                    anchors.fill: parent
                    color: 'transparent'

                    Text {
                        id: generateText
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

                anchors.left: generateContainer.right

                onPressed: {
                    const selected = 'config'

                    root.selected = selected
                    root.selectedChange(selected)
                }

                Rectangle {
                    id: config
                    anchors.fill: parent
                    color: 'transparent'

                    Text {
                        id: configText
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
