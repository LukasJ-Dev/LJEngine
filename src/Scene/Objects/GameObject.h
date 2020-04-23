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
protected:
    Scene *scene;
    std::vector<GameObject*> children;
    std::string GameObjectType = "GameObject";
    glm::vec2 localPosition, globalPosition, Scale;
    GameObject *parent;
    void setParent(GameObject *parent);
public:

    GLfloat Rotation;

    void attachChild(GameObject *child);

    void setScene(Scene *scene);

    glm::vec2 getPosition();
    glm::vec2 getScale();

    std::string getGameObjectType();

    std::vector<GameObject*> getChildren();

    GameObject* getParent();

    void setPosition(glm::vec2 Position);

    void setScale(glm::vec2 Scale);

    GameObject();
    GameObject(glm::vec2 Position, glm::vec2 Scale, GLfloat Rotation, std::string GameObjectType = "GameObject");
};


#endif //FLAPPYBIRD_GAMEOBJECT_H
