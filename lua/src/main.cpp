#include <iostream>
using namespace std;

#pragma comment (lib,"D:/Program Files (x86)/lua-5.3.5/lua5.3.5.lib")
#include "D:/Program Files (x86)/lua-5.3.5/src/lua.hpp"

void hello()
{
	printf("hello c++\r\n");
}

void hi(int num)
{
	printf("hi c++ %d\r\n", num);
}

int tolua_isnumber(lua_State* L, int idx)
{
	int top = lua_gettop(L);

	if (top < abs(idx))
	{
		return 1;
	}
	
	// lua_isnumber内部有string to number...
	return lua_isnumber(L, idx);
}

int tolua_C_hello_00(lua_State* L)
{
	{
		hello();
		return 0;
	}
}

int tolua_C_hi_00(lua_State* L)
{
	if (!tolua_isnumber(L, 1))
	{
		printf("lua_isnumber error\r\n");
	}

	int num = lua_tonumber(L, 1);
	if(1)
	{
		hi(num);
		return 0;
	}
}

void luatest()
{
	lua_State* lua_state = luaL_newstate();
	luaL_openlibs(lua_state);
	
    lua_register(lua_state, "hello", tolua_C_hello_00);
	lua_register(lua_state, "hi", tolua_C_hi_00);
    
    luaL_dofile(lua_state, "hello.lua"); 
    lua_close(lua_state);
}

int main()
{
    luatest();


    getchar();
    return 0;
}