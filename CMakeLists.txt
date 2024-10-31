cmake_minimum_required(VERSION 3.27)
project(change_style_of_naming)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/ilya/programming/Qt/6.8.0/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

qt6_wrap_ui(UI_HEADERS ${UIS_FILES})

add_executable(change_style_of_naming main.cpp
        src/project.cpp
        include/project.h
        src/UI.cpp
        include/UI.h
        src/save.cpp
        include/save.h
        src/change.cpp
        include/change.h
        include/helpingFunctions.h
        include/helpingFunctions.h
        src/helpingFunctions.cpp
        src/helpingFunctions.cpp
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
)

target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

include_directories(${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/cmake-build-debug/Change-Style-Of-Naming/include)#for ui_*

