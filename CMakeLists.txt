cmake_minimum_required(VERSION 4.3)
project(fscan)

set(CMAKE_CXX_STANDARD 23)

add_executable(fscan src/main.cpp
        src/scan.cpp)

target_include_directories(fscan
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)