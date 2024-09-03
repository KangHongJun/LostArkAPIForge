cmake_minimum_required(VERSION 3.26)

project(GUI VERSION 0.0.1)

set(CURL_ROOT "C:/cpp_tools/curl-8.9.0")
include_directories(${CURL_ROOT}/include)
link_directories(${CURL_ROOT}/lib)

set(GUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.h
)

add_library(GUI STATIC
        ${GUI_SOURCES}
        ../util/ReadConfig.h
        ../util/ReadConfig.cpp

)

target_link_libraries(GUI PRIVATE
        Qt6::Core
        Qt6::Widgets
)

target_include_directories(GUI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        Qt6::Core
        Qt6::Widgets
)