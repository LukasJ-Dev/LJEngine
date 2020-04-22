//
// Created by Lukas on 2020-04-08.
//

#ifndef FLAPPYBIRD_GAMEOBJECT_H
#define FLAPPYBIRD_GAMEOBJECT_H

#include "gl/glew.h"
#include <glm/glm.hpp>
#include <vector>

class Scene;

class GameObject {
private:
    Scene *scene;
    std::vector<GameObject*> children;
    std::string GameObjectType = "GameObject";
public:
    glm::vec2 Position, Size;
    GLfloat Rotation;

    void attachChild(GameObject *child);

    void setScene(Scene *scene);

    std::string getGameObjectType();

    std::vector<GameObject*> getChildren();

    GameObject();
    GameObject(glm::vec2 Position, glm::vec2 Size, GLfloat Rotation, std::string GameObjectType = "GameObject");
};


#endif //FLAPPYBIRD_GAMEOBJECT_H
