#ifndef _M_H
#define _M_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int m_open(lua_State* L);

int m_sin(lua_State* L);
int m_cos(lua_State* L);
int m_tan(lua_State* L);

int m_asin(lua_State* L);
int m_acos(lua_State* L);
int m_atan(lua_State* L);
int m_atan2(lua_State* L);

#endif
