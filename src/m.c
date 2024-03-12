#define _USE_MATH_DEFINES
#include <math.h>

#include "m.h"
#include "lua.h"

const struct luaL_Reg MMod[] = {
    { "sin", m_sin },
    { "cos", m_cos },
    { "tan", m_tan },
    { "asin", m_asin },
    { "acos", m_acos },
    { "atan", m_atan },
    { "atan2", m_atan2 },
    { NULL, NULL },
};

int m_open(lua_State* L) {
    lua_newtable(L);

    lua_pushstring(L, "PI");
    lua_pushnumber(L, M_PI);
    lua_settable(L, -3);

    luaL_setfuncs(L, (const luaL_Reg*)&MMod, 0);

    lua_setglobal(L, "m");

    return 0;
}

int m_sin(lua_State* L) {
    if (lua_gettop(L) != 1) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;

    float angle = lua_tonumber(L, 1);

    lua_pushnumber(L, sinf(angle));

    return 1;

ERR:
    return 0;
}

int m_cos(lua_State* L) {
    if (lua_gettop(L) != 1) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;

    float angle = lua_tonumber(L, 1);

    lua_pushnumber(L, cosf(angle));

    return 1;

ERR:
    return 0;

}

int m_tan(lua_State* L) {
    if (lua_gettop(L) != 1) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;

    float angle = lua_tonumber(L, 1);

    lua_pushnumber(L, tanf(angle));

    return 1;

ERR:
    return 0;

}

int m_asin(lua_State* L) {
    if (lua_gettop(L) != 1) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;

    float angle = lua_tonumber(L, 1);

    lua_pushnumber(L, asinf(angle));

    return 1;

ERR:
    return 0;

}

int m_acos(lua_State* L) {
    if (lua_gettop(L) != 1) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;

    float angle = lua_tonumber(L, 1);

    lua_pushnumber(L, acosf(angle));

    return 1;

ERR:
    return 0;

}

int m_atan(lua_State* L) {
    if (lua_gettop(L) != 1) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;

    float angle = lua_tonumber(L, 1);

    lua_pushnumber(L, atanf(angle));

    return 1;

ERR:
    return 0;
}

int m_atan2(lua_State* L) {
    if (lua_gettop(L) != 2) goto ERR;
    if (!lua_isnumber(L, 1)) goto ERR;
    if (!lua_isnumber(L, 2)) goto ERR;

    float y = lua_tonumber(L, 1);
    float x = lua_tonumber(L, 2);

    lua_pushnumber(L, atan2f(y, x));

    return 1;

ERR:
    return 0;
}


