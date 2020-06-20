//
// Created by Lukas on 2020-06-09.
//

#ifndef LJENGINE_LUAREFLECTION_H
#define LJENGINE_LUAREFLECTION_H

#include <rttr/registration.h>
#include "lua.hpp"

class LuaReflection {
public:
    static void CallFunctionFromScript(lua_State* luaState, const char* functionName);
    static int getPositionR(lua_State* luaState);
    static int setPositionR(lua_State* luaState);
    static int HandleInputR(lua_State *luaState);

private:
    LuaReflection() {}
};


#endif //LJENGINE_LUAREFLECTION_H
