#ifndef _GFX_H
#define _GFX_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int gfx_open(lua_State *L);
int gfx_clear(lua_State *L);
int gfx_text(lua_State* L);
int gfx_pixel(lua_State* L);
int gfx_line(lua_State* L);
int gfx_rect(lua_State* L);
int gfx_ellipse(lua_State *L);

#endif
