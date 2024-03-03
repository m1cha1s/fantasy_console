#include <raylib.h>

#include "btn.h"

const struct luaL_Reg BtnMod[] = {
    { "up", btn_up },
    { "down", btn_down },
    { "left", btn_left },
    { "right", btn_right },

    { "z", btn_z },
    { "x", btn_x },
    { "c", btn_c },
    { NULL, NULL },
};

int btn_open(lua_State* L) {
    lua_newtable(L);

    luaL_setfuncs(L, (const luaL_Reg*)&BtnMod, 0);

    lua_setglobal(L, "btn");

    return 0;
}

int btn_up(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_UP));
    return 1;
}

int btn_down(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_DOWN));
    return 1;
}

int btn_left(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_LEFT));
    return 1;
}
 
int btn_right(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_RIGHT));
    return 1;
}

int btn_z(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_Z));
    return 1;
}

int btn_x(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_X));
    return 1;
}

int btn_c(lua_State* L) {
    lua_pushboolean(L, IsKeyDown(KEY_C));
    return 1;
}