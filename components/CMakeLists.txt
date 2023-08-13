qt_add_library(components STATIC)

qt_add_qml_module(components
    URI components
    RESOURCE_PREFIX /
    VERSION 1.0
    QML_FILES
        ParamSelect.qml
        Input.qml
        Select.qml
    SOURCES
        parameter.h
        parameter.cpp
        record.h
        record.cpp
)

target_link_libraries(components
    PRIVATE Qt6::Quick
            Qt6::Gui
            Qt6::Sql
)
