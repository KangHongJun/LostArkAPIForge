cmake_minimum_required(VERSION 3.26)

project(util VERSION 1.0.0)


set(UTIL_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/ReadConfig.cpp
)

add_library(util STATIC ${UTIL_SOURCES})
target_include_directories(API PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)