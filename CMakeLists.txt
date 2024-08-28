cmake_minimum_required(VERSION 3.26)
project(LostArkAPIForge VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64/lib/cmake")
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64/bin")
set(QT6_PATH "C:/Qt/6.5.3/mingw_64/lib/cmake/")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

set(CURL_ROOT "C:/cpp_tools/curl-8.9.0")

set (SRC_PATH ${CMAKE_SOURCE_DIR}/src/)
set (API_PATH ${CMAKE_SOURCE_DIR}/src/API)
set (UI_PATH ${CMAKE_SOURCE_DIR}/src/GUI)
set (UTIL_PATH ${CMAKE_SOURCE_DIR}/src/util)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")

add_subdirectory(src/API)
add_subdirectory(src/GUI)
add_subdirectory(src/util)

add_executable(LostArkAPIForge
        main.cpp
)

include_directories("C:/Qt/6.5.3/mingw_64/bin")
link_directories("C:/Qt/6.5.3/mingw_64/bin")

include_directories(${CURL_ROOT}/include)
link_directories(${CURL_ROOT}/lib)

target_include_directories(LostArkAPIForge PRIVATE
        ${GUI_PATH}
        ${API_PATH}
        ${UTIL_PATH}
)

target_link_libraries(LostArkAPIForge
        util
        GUI
        API
        Qt6::Core
        Qt6::Widgets
        "C:/cpp_tools/curl-8.4.0/lib/libcurl.dll.a"
)
