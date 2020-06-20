//
// Created by Lukas on 2020-04-23.
//
#include "SceneLoader.h"
#include <Game.h>

Camera *camera;

std::vector<lua_State*> lStates;

Scene* SceneLoader::loadScene(std::string scenePath, Game *game) {
    std::ifstream i(scenePath);
    json j;
    i >> j;

    std::cout << j["sceneName"] << std::endl;

    GameObject *rootObject = new GameObject(
            glm::vec2(j["root"]["Position"][0],j["root"]["Position"][1]),
            glm::vec2(j["root"]["Scale"][0],j["root"]["Scale"][1]),j["root"]["Rotation"]);

    Scene* world = new Scene(*rootObject);
    checkObjects(j["root"]["children"], rootObject, game);
    return world;
}

void SceneLoader::checkObjects(json j, GameObject* parent, Game *game) {

    for(int i = 0; i < j.size(); i++) {
        GameObject *object;

        if (j.at(i)["GameObjectType"] == "Sprite2D") {
            object = new Sprite2D(ResourceManager::GetTexture(j.at(i)["sprite"]),
                    glm::vec2(j.at(i)["Position"][0],j.at(i)["Position"][1]),
                    glm::vec2(j.at(i)["Scale"][0],j.at(i)["Scale"][1]),j.at(i)["Rotation"]);
        }
        else if (j.at(i)["GameObjectType"] == "Camera") {
            object = new Camera(
                    glm::vec2(j.at(i)["Position"][0],j.at(i)["Position"][1]),
                    glm::vec2(j.at(i)["Scale"][0],j.at(i)["Scale"][1]),j.at(i)["Rotation"],
                    glm::vec2(j.at(i)["Size"][0], j.at(i)["Size"][0]));
            camera = static_cast<Camera *>(object);
        }
        else if(j.at(i)["GameObjectType"] == "RigidBody") {
            object = new RigidBody(
                    glm::vec2(j.at(i)["Position"][0],j.at(i)["Position"][1]),
                    glm::vec2(j.at(i)["Scale"][0],j.at(i)["Scale"][1]),j.at(i)["Rotation"]);
        }
        else {
            object = new GameObject(
                    glm::vec2(j.at(i)["Position"][0],j.at(i)["Position"][1]),
                    glm::vec2(j.at(i)["Scale"][0],j.at(i)["Scale"][1]),j.at(i)["Rotation"]);
        }

        GameObject* objectPointer = parent->attachChild(object);

        if(j.at(i)["Script"] != nullptr) {
            std::cout << "Hello World" << std::endl;
            lStates.push_back(luaL_newstate());
            luaL_openlibs(lStates.back());

            //TEMP
            luaL_newmetatable(lStates.back(), "ObjectMetaTable");
            lua_pushstring(lStates.back(), "__index");
            lua_pushlightuserdata(lStates.back(), objectPointer);
            lua_pushcclosure(lStates.back(), LuaReflection::getPositionR, 1);
            lua_settable(lStates.back(), -3);

            lua_pushstring(lStates.back(), "__newindex");
            lua_pushlightuserdata(lStates.back(), objectPointer);
            lua_pushcclosure(lStates.back(), LuaReflection::setPositionR, 1);
            lua_settable(lStates.back(), -3);

            lua_getglobal(lStates.back(), "position");
            luaL_getmetatable(lStates.back(), "ObjectMetaTable");
            lua_setmetatable(lStates.back(), -2);

            lua_newtable(lStates.back());
            lua_pushvalue(lStates.back(), lua_gettop(lStates.back()));
            lua_setglobal(lStates.back(), "Input");
            lua_pushcfunction(lStates.back(), LuaReflection::HandleInputR);
            lua_setfield(lStates.back(), -2, "isKeyDown");

            //TEMP
            std::string scriptName = j.at(i)["Script"];
            std::string scriptPath = game->getGamePath() + "scripts/" + scriptName;
            luaL_dofile(lStates.back(), scriptPath.c_str());
        }


        if(j.at(i)["children"].size() > 0){
            checkObjects(j.at(i)["children"], object, game);
        }
    }
}

Camera* SceneLoader::getCamera() {
    return camera;
}

std::vector<lua_State*> SceneLoader::getState() {
    return lStates;
}