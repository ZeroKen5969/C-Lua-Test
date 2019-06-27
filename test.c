#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int test();

int main()
{
    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    lua_getglobal(L, "print");
    lua_pushstring(L, "test test test");
    lua_call(L, 1, 0);

    lua_getglobal(L, "print");
    lua_pushstring(L, "test test test");
    lua_call(L, 1, 0);

    lua_getglobal(L, "print");
    lua_pushstring(L, "test test test");
    lua_call(L, 1, 0);

    lua_pushcfunction(L, test);
    lua_setglobal(L, "test");
    
    lua_getglobal(L, "test");
    lua_pushstring(L, "test my my my");
    lua_call(L, 1, 0);

    lua_close(L);
    
    return 0;
}

static int test(lua_State *L)
{
    const char *s = lua_tostring(L, 1);
    printf("%s", s);

    return 0;
}