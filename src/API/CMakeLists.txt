cmake_minimum_required(VERSION 3.26)

project(API VERSION 1.0.0)

set(CURL_PATH "C:/cpp_tools/curl-8.9.0/include")

set(API_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/CurlTest.cpp
)

add_library(API STATIC ${API_SOURCES})
target_include_directories(API PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CURL_PATH}
)