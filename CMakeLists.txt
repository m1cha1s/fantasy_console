cmake_minimum_required(VERSION 3.16)

project(fantasy_console C)

set(CMAKE_C_STANDARD 99)

execute_process(
    COMMAND git submodule update --init
)

execute_process(
    COMMAND patch -N -r- ${CMAKE_CURRENT_LIST_DIR}/luajit/src/Makefile ${CMAKE_CURRENT_LIST_DIR}/patches/luajitMk.patch
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/raylib)

add_custom_target(luajit
    COMMENT Compiling luajit
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/luajit/src
    COMMAND make 
    VERBATIM
)

add_executable(fantasy_console
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/src/gfx.c
)

target_link_libraries(fantasy_console
    ${CMAKE_CURRENT_LIST_DIR}/luajit/src/libluajit.a
    m
    raylib
)

target_include_directories(fantasy_console PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/luajit/src
)

add_dependencies(fantasy_console luajit)
