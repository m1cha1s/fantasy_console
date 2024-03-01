cmake_minimum_required(VERSION 3.16)

execute_process(
    COMMAND git submodule update --init
)

include(luajit.cmake)

project(fantasy_console C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/raylib)

add_executable(fantasy_console
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/src/gfx.c
)

target_link_libraries(fantasy_console PRIVATE
    luajit
    raylib
)
