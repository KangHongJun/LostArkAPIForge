cmake_minimum_required(VERSION 3.26)

project(GUI VERSION 0.0.1)

set(GUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.h
)

add_library(GUI STATIC ${GUI_SOURCES})
target_link_libraries(GUI PRIVATE
        Qt6::Core
        Qt6::Widgets
)

target_include_directories(GUI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        Qt6::Core
        Qt6::Widgets
)