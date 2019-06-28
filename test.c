
#ifdef __cplusplus

#include "lua.hpp"

#else

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#endif

int luaopen_mylib(lua_State *L);
static int add(lua_State *L);

static const luaL_Reg mylib[] = {
    {"add", add},
    {NULL, NULL}
};

int main()
{
    lua_State *L = luaL_newstate();

    if(luaL_dofile(L, "test.lua")) {
        perror("Do file error!");
        return 1;
    }

    lua_close(L);

    return 0;
}

int luaopen_mylib(lua_State *L)
{
    luaL_newlib(L, mylib);
    return 1;
}

static int add(lua_State *L)
{
    int a = luaL_checkinteger(L, 1);
    int b = luaL_checkinteger(L, 2);
    lua_pushinteger(L, a + b);
    return 1;
}