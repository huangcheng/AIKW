cmake_minimum_required(VERSION 3.16)

project(AIKW VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(AIKW
    main.cpp
)

qt_add_qml_module(AIKW
    URI AIKW
    VERSION 1.0
    QML_FILES Main.qml
              TitleBar.qml
              Configuration.qml
              Generation.qml
              Title.qml
              Input.qml
)

qt_add_resources(AIKW "fonts"
    PREFIX "/"
    BIG_RESOURCES
    FILES fonts/SourceHanSansSC-Regular.otf
          fonts/SourceHanSansSC-Bold.otf
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
)

install(TARGETS AIKW
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
