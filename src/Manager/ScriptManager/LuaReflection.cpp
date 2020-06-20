//
// Created by Lukas on 2020-06-09.
//

#include <Scene/Objects/GameObject.h>
#include <iostream>
#include "Manager/KeyHandler.h"
#include "LuaReflection.h"

void LuaReflection::CallFunctionFromScript(lua_State* luaState, const char* functionName) {
    lua_getglobal(luaState, functionName);
    if(lua_isfunction(luaState,-1)) {
        lua_pcall(luaState, 0, 0, 0);
    }
}

int LuaReflection::getPositionR(lua_State* luaState) {
    GameObject* gameObject = (GameObject*)lua_touserdata(luaState, lua_upvalueindex(1));
    const char* index = lua_tostring(luaState, -1);
    if(gameObject != nullptr) {
        if(strcmp(index, "x") == 0) {
            lua_pushnumber(luaState, gameObject->getPosition().x);
        } else if(strcmp(index, "y") == 0) {
            lua_pushnumber(luaState, gameObject->getPosition().y);
        }
        return 1;
    }
    return 0;
}

int LuaReflection::setPositionR(lua_State* luaState) {
    GameObject* gameObject = (GameObject*)lua_touserdata(luaState, lua_upvalueindex(1));
    const char* index = lua_tostring(luaState, -2);
    if(gameObject != nullptr) {
        if(strcmp(index, "x") == 0) {

            gameObject->setPosition(
                    glm::vec2(
                            lua_tonumber(luaState, -1),
                            gameObject->getPosition().y)
                            );

        } else if(strcmp(index, "y") == 0) {
            gameObject->setPosition(
                    glm::vec2(
                            gameObject->getPosition().x,
                            lua_tonumber(luaState, -1))
            );
        }
        return 1;
    }
}

int LuaReflection::HandleInputR(lua_State *luaState) {
    int keyCode = lua_tonumber(luaState, -1);
    if(keyCode == KeyHandler::getKeyPressed()) {
        lua_pushboolean(luaState, true);
    } else {
        lua_pushboolean(luaState, false);
    }

    return 1;
}
