cmake_minimum_required(VERSION 3.16)

project(AIKW VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Gui)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(AIKW

    generation.h
    generation.cpp
    main.cpp
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
    SOURCES   description.h
              description.cpp
)

qt_add_resources(AIKW "fonts"
    PREFIX "/"
    BIG_RESOURCES
    FILES fonts/SourceHanSansSC-Regular.otf
          fonts/SourceHanSansSC-Bold.otf
)

qt_add_resources(AIKW "images"
    PREFIX "/"
    FILES images/PlusCircleF.svg
)

set_target_properties(AIKW PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(AIKW
    PRIVATE Qt6::Quick
            Qt6::Gui
)

install(TARGETS AIKW
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
