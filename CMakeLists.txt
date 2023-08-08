cmake_minimum_required(VERSION 3.16)

project(AIKW VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Gui Sql)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(AIKW
    generation.h
    generation.cpp
    main.cpp
    description.h
    description.cpp
)

qt_add_qml_module(AIKW
    URI AIKW
    VERSION 1.0
    QML_FILES qml/Main.qml
              qml/TitleBar.qml
              qml/Configuration.qml
              qml/Generation.qml
              qml/Title.qml
              qml/Input.qml
              qml/InputArea.qml
              qml/Description.qml

)

add_subdirectory(components)

qt_add_resources(AIKW "fonts"
    PREFIX "/"
    BIG_RESOURCES
    FILES fonts/SourceHanSansSC-Regular.otf
          fonts/SourceHanSansSC-Bold.otf
)

qt_add_resources(AIKW "images"
    PREFIX "/"
    FILES images/PlusCircleF.svg
          images/Trash.svg
          images/TrashHover.svg
)

set_target_properties(AIKW PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER aikw.cheng.im
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(AIKW
    PRIVATE Qt6::Quick
            Qt6::Gui
            Qt6::Sql
)

target_link_libraries(AIKW PRIVATE componentsplugin)

install(TARGETS AIKW
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


