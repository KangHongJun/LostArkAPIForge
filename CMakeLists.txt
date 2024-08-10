cmake_minimum_required(VERSION 3.26)

project(LostArkAPIForge VERSION 1.0.0)

find_package(PkgConfig REQUIRED)
set(CMAKE_CXX_STANDARD 14)

set (SRC_PATH ${CMAKE_SOURCE_DIR}/src/)
set (API_PATH ${CMAKE_SOURCE_DIR}/src/API)
#set (UI_PATH ${CMAKE_SOURCE_DIR}/src/UI)
set (UTIL_PATH ${CMAKE_SOURCE_DIR}/src/util)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")
set(CURL_PATH "C:/cpp_tools/curl-8.9.0/include")

add_subdirectory(src/API)
add_subdirectory(src/util)

add_executable(LostArkAPIForge
        main.cpp
)

target_include_directories(LostArkAPIForge PRIVATE
        ${API_PATH}
        ${UTIL_PATH}
        ${CURL_PATH})

target_link_libraries(LostArkAPIForge
        API
        util
        "C:/cpp_tools/curl-8.4.0/lib/libcurl.dll.a")
