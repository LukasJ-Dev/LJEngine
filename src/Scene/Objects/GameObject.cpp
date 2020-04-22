//
// Created by Lukas on 2020-04-08.
//

#include <iostream>
#include "GameObject.h"

#include "Sprite2D.h"

#include "Scene/Scene.h"

GameObject::GameObject()
    : Position(0, 0), Size(1, 1), Rotation(0.0f) { }

GameObject::GameObject(glm::vec2 Position, glm::vec2 Size, GLfloat Rotation, std::string GameObjectType)
    : Position(Position), Size(Size), Rotation(Rotation), GameObjectType(GameObjectType) {}

void GameObject::attachChild(GameObject *child) {
    children.push_back(child);
    child->setScene(scene);
}

void GameObject::setScene(Scene *scene) {
    this->scene = scene;
    std::cout << this->getGameObjectType() << std::endl;
    if(this->getGameObjectType() == "Sprite2D") {

        this->scene->addToRenderer(((Sprite2D*)this));
    }
    for (int i = 0; i < children.size(); i++) {
        children[i]->setScene(scene);
    }
}

std::vector<GameObject*> GameObject::getChildren() {
    return children;
}

std::string GameObject::getGameObjectType() {
    return GameObjectType;
}