//
// Created by Lukas on 2020-04-23.
//
#include "SceneLoader.h"

Camera *camera;

Scene* SceneLoader::loadScene(std::string scenePath) {
    std::ifstream i(scenePath);
    json j;
    i >> j;

    std::cout << j["sceneName"] << std::endl;

    GameObject *rootObject = new GameObject(
            glm::vec2(j["root"]["Position"][0],j["root"]["Position"][1]),
            glm::vec2(j["root"]["Scale"][0],j["root"]["Scale"][1]),j["root"]["Rotation"]);

    Scene* world = new Scene(*rootObject);
    checkObjects(j["root"]["children"], rootObject);
    return world;
}

void SceneLoader::checkObjects(json j, GameObject* parent) {

    for(int i = 0; i < j.size(); i++) {
        GameObject *object;
        std::cout << j.at(i)["GameObjectType"] << std::endl;
        if (j.at(i)["GameObjectType"] == "GameObject") {
            object = new GameObject(
                    glm::vec2(j.at(i)["Position"][0],j.at(i)["Position"][1]),
                    glm::vec2(j.at(i)["Scale"][0],j.at(i)["Scale"][1]),j.at(i)["Rotation"]);
        }
        else if (j.at(i)["GameObjectType"] == "Sprite2D") {
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

        std::cout << "Pos: ";
        std::cout << j.at(i)["Position"][0];
        std::cout << ", ";
        std::cout << j.at(i)["Position"][1] << std::endl;

        std::cout << "Scale: ";
        std::cout << j.at(i)["Scale"][0];
        std::cout << ", ";
        std::cout << j.at(i)["Scale"][1] << std::endl;

        std::cout << "Rotation: ";
        std::cout << j.at(i)["Rotation"] << std::endl;

        parent->attachChild(object);
        if(j.at(i)["children"].size() > 0){
            checkObjects(j.at(i)["children"], object);
        }
    }
}

Camera* SceneLoader::getCamera() {
    return camera;
}