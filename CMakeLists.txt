cmake_minimum_required(VERSION 3.27)
project(change_style_of_naming)

set(CMAKE_CXX_STANDARD 23)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(change_style_of_naming main.cpp
        src/text.cpp
        include/text.h
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
)
