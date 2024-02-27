#include <stdio.h>

// Raylib
//#include <raylib.h>

// Lua
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <luajit.h>

int main(int argc, char** argv) {
    /*InitWindow(800,800, "fantasy_console");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
    */

//    int status = 0;
    lua_State *L;

    L = luaL_newstate();
    if (!L) {
        return -1;
    }

    luaL_openlibs(L);

    if (argc > 1) {
        luaL_loadfile(L, argv[1]);
        int ret = lua_pcall(L, 0, 0, 0);

        if (ret != 0) {
            fprintf(stderr, "%s\n", lua_tostring(L, -1));
            return 1;
        }
    }

    lua_close(L);

    return 0;
}
