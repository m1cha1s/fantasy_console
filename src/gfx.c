#include <raylib.h>

#include "gfx.h"

const struct luaL_Reg GfxMod[] = {
    { "clear", gfx_clear },
    { "text", gfx_text },
    { "pixel", gfx_pixel },
    { "line", gfx_line },
    { "rect", gfx_rect },
    { "ellipse", gfx_ellipse },
    { NULL, NULL },
};

int gfx_open(lua_State *L) {
    lua_newtable(L);

    luaL_setfuncs(L, (const luaL_Reg*)&GfxMod, 0);

    lua_setglobal(L, "gfx");

    return 0;
}

static Color tableToColor(lua_State *L, int tableIdx) {
    Color c = {0,0,0,255};

    lua_pushstring(L, "r");
    lua_gettable(L, tableIdx);
    if (lua_isnumber(L, -1)) {
        c.r = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pushstring(L, "g");
    lua_gettable(L, tableIdx);
    if (lua_isnumber(L, -1)) {
        c.g = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pushstring(L, "b");
    lua_gettable(L, tableIdx);
    if (lua_isnumber(L, -1)) {
        c.b = (unsigned char)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pushstring(L, "a");
    lua_gettable(L, tableIdx);
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

    c = tableToColor(L, -2);

DONE:

    ClearBackground(c);
    
    return 0;
}

int gfx_text(lua_State *L) {

    if (lua_gettop(L) < 5) goto ERR;

    if (!lua_isstring(L, 1)) goto ERR;
    if (!lua_isnumber(L, 2)) goto ERR;
    if (!lua_isnumber(L, 3)) goto ERR;
    if (!lua_isnumber(L, 4)) goto ERR;

    if (!lua_istable(L, 5)) goto ERR;
    
    const char *text = lua_tostring(L, 1);
    int x = lua_tointeger(L, 2);
    int y = lua_tointeger(L, 3);
    int size = lua_tointeger(L, 4);
    Color c = tableToColor(L, 5);

    DrawText(text, x, y, size, c);
    
    return 0;

ERR:

    luaL_error(L, "Invalid args");
    return 0;
}

int gfx_pixel(lua_State* L) {
    if (lua_gettop(L) < 3) goto ERR;

    if (!lua_isnumber(L, 1)) goto ERR;
    if (!lua_isnumber(L, 2)) goto ERR;
    if (!lua_istable(L, 3)) goto ERR;

    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    Color c = tableToColor(L, 3);

    DrawPixel(x, y, c);

    return 0;

ERR:
    luaL_error(L, "Invalid args");
    return 0;
}

int gfx_line(lua_State* L) {
    if (lua_gettop(L) < 5) goto ERR;

    if (!lua_isnumber(L, 1)) goto ERR;
    if (!lua_isnumber(L, 2)) goto ERR;
    if (!lua_isnumber(L, 3)) goto ERR;
    if (!lua_isnumber(L, 4)) goto ERR;
    if (!lua_istable(L, 5)) goto ERR;

    int x1 = lua_tointeger(L, 1);
    int y1 = lua_tointeger(L, 2);
    int x2 = lua_tointeger(L, 3);
    int y2 = lua_tointeger(L, 4);
    Color c = tableToColor(L, 5);

    DrawLine(x1, y1, x2, y2, c);

    return 0;

ERR:
    luaL_error(L, "Invalid args");
    return 0;
}

int gfx_rect(lua_State* L) {
    if (lua_gettop(L) < 5) goto ERR;

    if (!lua_isnumber(L, 1)) goto ERR;
    if (!lua_isnumber(L, 2)) goto ERR;
    if (!lua_isnumber(L, 3)) goto ERR;
    if (!lua_isnumber(L, 4)) goto ERR;
    if (!lua_istable(L, 5)) goto ERR;

    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    int w = lua_tointeger(L, 3);
    int h = lua_tointeger(L, 4);
    Color c = tableToColor(L, 5);

    DrawRectangle(x, y, w, h, c);

    return 0;

ERR:
    luaL_error(L, "Invalid args");
    return 0;
}

int gfx_ellipse(lua_State* L) {
    if (lua_gettop(L) < 5) goto ERR;

    if (!lua_isnumber(L, 1)) goto ERR;
    if (!lua_isnumber(L, 2)) goto ERR;
    if (!lua_isnumber(L, 3)) goto ERR;
    if (!lua_isnumber(L, 4)) goto ERR;
    if (!lua_istable(L, 5)) goto ERR;

    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    double rx = lua_tonumber(L, 3);
    double ry = lua_tonumber(L, 4);
    Color c = tableToColor(L, 5);

    DrawEllipse(x, y, rx, ry, c);

    return 0;

ERR:
    luaL_error(L, "Invalid args");
    return 0;
}
