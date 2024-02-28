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

static Color tableToColor(lua_State *L) {
    Color c = {0,0,0,255};

    lua_pushstring(L, "r");
    lua_gettable(L, -2);
    if (lua_isnumber(L, -1)) {
        c.r = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pushstring(L, "g");
    lua_gettable(L, -2);
    if (lua_isnumber(L, -1)) {
        c.g = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pushstring(L, "b");
    lua_gettable(L, -2);
    if (lua_isnumber(L, -1)) {
        c.b = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pushstring(L, "a");
    lua_gettable(L, -2);
    if (lua_isnumber(L, -1)) {
        c.a = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }

    return c;
}

int gfx_clear(lua_State *L) {

    Color c = {0,0,0,0};

    if (lua_gettop(L) < 1) goto DONE;
    if (!lua_istable(L, 1)) goto DONE;

    c = tableToColor(L);

DONE:

    ClearBackground(c);
    
    return LUA_OK;
}

