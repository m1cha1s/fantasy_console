#include <stdio.h>

// Raylib
#include <raylib.h>

// Lua
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <luajit.h>

#include "gfx.h"
#include "btn.h"

lua_State *L;

const char* script = NULL;

static int lua_init() {
    L = luaL_newstate();
    if (!L) {
        return -1;
    }

    // FIXME: Remove this it is unnecessary
    luaL_openlibs(L);

    // Add gfx capabilities under gfx module
    gfx_open(L);
    // Add input capabilities under btn module
    btn_open(L);

    if (luaL_dofile(L, script) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    return 0;
}

int main(int argc, char** argv) {
    // TODO: Add some kind of rom browser
    if (argc <= 1) {
        script = "../../../examples/hello.lua";
    }
    else {
        script = argv[1];
    }

    lua_init(); // TODO: Error reporting

    InitWindow(800,800, "fantasy_console");

    SetTargetFPS(60);

    lua_getglobal(L, "Init");
    if (lua_isfunction(L, -1)) {
        if (lua_pcall(L, 0, 1, 0) == LUA_OK) {
            lua_pop(L, lua_gettop(L));
        }
    }
    lua_pop(L, lua_gettop(L));

    while(!WindowShouldClose()) {
        // Perform a reload
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_R)) {
            lua_close(L);
            lua_init(); // TODO: Error reporting

            lua_getglobal(L, "Init");
            if (lua_isfunction(L, -1)) {
                if (lua_pcall(L, 0, 1, 0) == LUA_OK) {
                    lua_pop(L, lua_gettop(L));
                }
            }
            lua_pop(L, lua_gettop(L));
        }

        // Call the lua update funciton
        lua_getglobal(L, "Update");
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, (double)GetFrameTime());
            if (lua_pcall(L, 1, 1, 0) == LUA_OK) {
                lua_pop(L, lua_gettop(L));
            }
        }
        lua_pop(L, lua_gettop(L));

        BeginDrawing();

        // Call the lua draw funciton
        lua_getglobal(L, "Draw");
        if (lua_isfunction(L, -1)) {
            if (lua_pcall(L, 0, 1, 0) == LUA_OK) {
                lua_pop(L, lua_gettop(L));
            }
        }
        lua_pop(L, lua_gettop(L));

        EndDrawing();
    }

    // Call the lua deinit funciton
    lua_getglobal(L, "Deinit");
    if (lua_isfunction(L, -1)) {
        if (lua_pcall(L, 0, 1, 0) == LUA_OK) {
            lua_pop(L, lua_gettop(L));
        }
    }
    lua_pop(L, lua_gettop(L));

    CloseWindow();
    
    lua_close(L);
    return 0;
}
