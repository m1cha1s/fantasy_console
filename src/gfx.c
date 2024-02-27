#include <raylib.h>

#include "gfx.h"

const struct luaL_Reg GfxMod[] = {
    { "clear", gfx_clear },
};

int gfx_open(lua_State *L) {
    lua_newtable(L);

    luaL_setfuncs(L, (const luaL_Reg*)&GfxMod, 0);

    lua_setglobal(L, "gfx");

    return 0;
}

int gfx_clear(lua_State *L) {
    unsigned char r=0,g=0,b=0,a=255;

    if (lua_isnumber(L, 1) && lua_gettop(L) >= 1) {
        r = lua_tointeger(L, 1);
    }
    if (lua_isnumber(L, 2) && lua_gettop(L) >= 2) {
        g = lua_tointeger(L, 2);
    }
    if (lua_isnumber(L, 3) && lua_gettop(L) >= 3) {
        b = lua_tointeger(L, 3);
    }
    if (lua_isnumber(L, 4) && lua_gettop(L) >= 4) {
        a = lua_tointeger(L, 4);
    }

    ClearBackground((Color){r,g,b,a});
    
    return LUA_OK;
}

