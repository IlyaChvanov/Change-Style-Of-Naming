cmake_minimum_required(VERSION 3.27)
project(change_style_of_naming)

set(CMAKE_CXX_STANDARD 23)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(change_style_of_naming main.cpp
        src/Text.cpp
        include/Text.h
        src/UI.cpp
        include/UI.h
        src/Save.cpp
        include/Save.h
        src/Change.cpp
        include/Change.h)
