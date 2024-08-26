cmake_minimum_required(VERSION 3.26)

project(GUI VERSION 0.0.1)

set(GUI_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
)

add_library(GUI STATIC ${GUI_SOURCES})
target_include_directories(GUI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)