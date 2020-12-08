cmake_minimum_required(VERSION 3.14)

project(Timer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Multimedia REQUIRED)

add_executable(${PROJECT_NAME}
        qml.qrc
        src/main.cpp
        src/timer.cpp
        include/timer.h
        src/logger.cpp
        include/logger.h
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Multimedia
        )