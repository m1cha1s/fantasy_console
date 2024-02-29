cmake_host_system_information(RESULT SYSTEM_NAME QUERY OS_NAME)

if (${SYSTEM_NAME} MATCHES "Windows")

    add_custom_target(luajitSrc
        COMMENT "Compiling luajit"
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/luajit/src
        COMMAND msvcbuild.bat static
        BYPRODUCTS ${CMAKE_CURRENT_LIST_DIR}/luajit/src/lua51.lib
        VERBATIM
    )

    set(LUAJIT_LIBS ${CMAKE_CURRENT_LIST_DIR}/luajit/src/luajit.lib ${CMAKE_CURRENT_LIST_DIR}/luajit/src/lua51.lib)

else()

    execute_process(
        COMMAND patch -N -r- ${CMAKE_CURRENT_LIST_DIR}/luajit/src/Makefile ${CMAKE_CURRENT_LIST_DIR}/patches/luajitMk.patch
    )

    add_custom_target(luajitSrc
        COMMENT "Compiling luajit"
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/luajit/src
        COMMAND make
        BYPRODUCTS ${CMAKE_CURRENT_LIST_DIR}/luajit/src/libluajit.a
        VERBATIM
    )

    set(LUAJIT_LIBS ${CMAKE_CURRENT_LIST_DIR}/luajit/src/libluajit.a)

endif()

add_library(luajit INTERFACE)

add_dependencies(luajit luajitSrc)

target_link_libraries(luajit INTERFACE ${LUAJIT_LIBS})
target_include_directories(luajit INTERFACE ${CMAKE_CURRENT_LIST_DIR}/luajit/src)
