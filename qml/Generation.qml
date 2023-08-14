import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Window

import components

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
                generation.descriptions_add()
            }
        }

        GridLayout {
            columns: 3
            rowSpacing: 10
            columnSpacing: 40

            Repeater {
                model: generation.descriptions

                Description {
                    required property int index

                    description: generation.descriptions[index].description
                    weight: generation.descriptions[index].weight

                    onDescriptionChanged: {
                        generation.descriptions[index].description = description
                    }

                    onWeightChanged: {
                        generation.descriptions[index].weight = weight
                    }

                    onDeleted: {
                        generation.descriptions_remove(index)
                    }
                }
            }
        }
    }

    ColumnLayout {
        spacing: root.gap

        Title {
            title: '常用'

            Layout.preferredHeight: 14
            Layout.fillWidth: true

            hasAdd: true

            onAdded: {
                generation.parameters_add()
            }
        }

        GridLayout {
            columns: 3
            rowSpacing: 10
            columnSpacing: 40

            Repeater {
                model: generation.parameters

                ParamSelect {
                    required property int index

                    parameter: generation.parameters[index].description
                    weight: generation.parameters[index].weight

                    onParameterChanged: param => {
                                            generation.parameters[index].description = parameter
                                        }

                    onWeightChanged: {
                        generation.parameters[index].weight = weight
                    }

                    onDeleted: {
                        generation.parameters_remove(index)
                    }
                }
            }
        }
    }

    ColumnLayout {
        spacing: root.gap

        Title {
            title: 'MJ官方参数'

            Layout.preferredHeight: 14
            Layout.fillWidth: true
        }

        GridLayout {
            columns: 3
            rowSpacing: 10
            columnSpacing: 40

            RowLayout {
                ALabel {
                    text: '风格化'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Input {
                    placeholder: '默认100, 0-1000'

                    text: generation.style

                    onTextChanged: {
                        generation.style = text
                    }

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            RowLayout {
                ALabel {
                    text: '版本'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Select {
                    currentIndex: model.findIndex((item) => item === generation.version)
                    model: ['--v 5.2', '--v 5.1', '--niji 5 --style cute', '--niji 5 --style scenic']
                    placeholder: '不同版本模型'

                    onActivated: (index) => {
                        generation.version = model[index]
                    }

                    Layout.fillWidth: true
                    Layout.preferredHeight: 34
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            RowLayout {
                ALabel {
                    text: '质量'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Input {
                    placeholder: '0-100, 值越大变化越大'

                    text: generation.quality

                    onTextChanged: {
                        generation.quality = text
                    }

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            RowLayout {
                ALabel {
                    text: '混乱'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Input {
                    placeholder: '0-100, 改变结果的多样性'

                    text: generation.chaos

                    onTextChanged: {
                        generation.chaos = text
                    }

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            RowLayout {
                ALabel {
                    text: '种子'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Input {
                    placeholder: '控制图片的相似性'

                    text: generation.seed

                    onTextChanged: {
                        generation.seed = text
                    }

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            RowLayout {
                ALabel {
                    text: '比例'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Select {
                    currentIndex: model.findIndex((item) => item === generation.aspect)
                    model: ['3:4', '16:9', '21:9', '9:16']
                    placeholder: '宽高比'

                    onActivated: (index) => {
                        generation.aspect = model[index]
                    }

                    Layout.fillWidth: true
                    Layout.preferredHeight: 34
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            RowLayout {
                ALabel {
                    text: '重复'

                    Layout.preferredHeight: 36
                    Layout.preferredWidth: 100
                    Layout.alignment: Qt.AlignVCenter
                }

                Input {
                    placeholder: '控制图片的相似性'

                    text: generation.repeat

                    onTextChanged: {
                        generation.repeat = text
                    }

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                }
            }
        }
    }

    ColumnLayout {
        spacing: root.gap

        Layout.topMargin: 100

        RowLayout {
            Title {
                title: '生成结果'

                Layout.fillWidth: true
            }

            RowLayout {
                spacing: 20

                MouseArea {
                    width: 50
                    height: 14

                    Layout.preferredWidth: 50

                    RowLayout {
                        spacing: 2

                        Image {
                            source: '/images/FormatPainter.svg'

                            width: 16
                            height: 16
                        }

                        Text {
                            text: '清空'

                            font.pixelSize: 14
                        }
                    }

                    onPressed: generation.clear()
                }

                MouseArea {
                    width: 50
                    height: 14
                    Layout.preferredWidth: 50

                    RowLayout {
                        spacing: 2

                        Image {
                            source: '/images/Copy.svg'

                            width: 16
                            height: 16
                        }

                        Text {
                            text: '复制'

                            font.pixelSize: 14
                        }
                    }

                    onPressed: generation.copy()
                }
            }
        }

        InputArea {
            readOnly: true

            text: generation.prompt ?? ''

            Layout.fillWidth: true
            Layout.preferredHeight: 80
        }
    }

    Component.onCompleted: {
        const { os } = Qt.platform

            if (os === 'windows') {
                root.gap = 20
            }
        }
    }
