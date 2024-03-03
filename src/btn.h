#ifndef _BTN_H
#define _BTN_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int btn_open(lua_State* L);

int btn_up(lua_State* L);
int btn_down(lua_State* L);
int btn_left(lua_State* L);
int btn_right(lua_State* L);

int btn_z(lua_State* L);
int btn_x(lua_State* L);
int btn_c(lua_State* L);

#endif
