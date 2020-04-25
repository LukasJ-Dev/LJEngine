//
// Created by Lukas on 2020-04-23.
//

#ifndef LJENGINE_SCENELOADER_H
#define LJENGINE_SCENELOADER_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>
#include "Scene/Scene.h"
#include "Scene/Objects/RigidBody.h"
#include "ResourceManager.h"

using json = nlohmann::json;

class SceneLoader {
private:
    static void checkObjects(json j, GameObject* parent);
public:
    static Camera* getCamera();
    static Scene* loadScene(std::string scenePath);
};


#endif //LJENGINE_SCENELOADER_H
