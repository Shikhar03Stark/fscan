cmake_minimum_required(VERSION 4.3)
project(fscan)

set(CMAKE_CXX_STANDARD 23)

add_executable(fscan src/main.cpp
        src/scan.cpp
        src/error.cpp)

target_include_directories(fscan
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Keep diagnostics scoped to this target and use the native warning flags for
# each supported compiler family.
if (MSVC)
    target_compile_options(fscan PRIVATE /W4 /permissive- /sdl)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(fscan PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wsign-conversion
            -Wshadow
            -Wformat=2
    )
endif ()
