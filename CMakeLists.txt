cmake_minimum_required(VERSION 3.27)
project(snake_case_to_CamelCase)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(snake_case_to_CamelCase
        src/main.cpp
        include/ChangeVariables.h
        include/ChangeFunctions.h
        include/Interfaces/CamelToSnake.h
        include/ChangeClasses.h
        include/Interfaces/AddUnderLineToPrivateFields.h
        src/SnakeToCamel.cpp
        src/CamelToSnake.cpp
        src/ChangeFile.cpp
        include/ChangeFile.h
        src/CreateNewFile.cpp
        include/CreateNewFile.h
        src/AddUnderLineToPrivateFields.cpp
        src/ChangeClasses.cpp
        src/ChangeFunctions.cpp
        src/ChangeVariables.cpp)
