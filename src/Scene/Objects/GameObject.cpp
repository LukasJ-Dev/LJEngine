//
// Created by Lukas on 2020-04-08.
//

#include <iostream>
#include "GameObject.h"

#include "Sprite2D.h"

#include "Scene/Scene.h"

GameObject::GameObject()
    : localPosition(0, 0), Scale(1, 1), Rotation(0.0f) { }

GameObject::GameObject(glm::vec2 Position, glm::vec2 Scale, GLfloat Rotation, std::string GameObjectType)
    : localPosition(Position), Scale(Scale), Rotation(Rotation), GameObjectType(GameObjectType), globalPosition(Position) {}

void GameObject::attachChild(GameObject *child) {
    children.push_back(child);
    child->setScene(scene);
    child->setParent(this);
}

void GameObject::setParent(GameObject *parent) {
    this->globalPosition = this->localPosition + parent->globalPosition;
    std::cout << parent->globalPosition.x << std::endl;
    this->parent = parent;
}

void GameObject::setScene(Scene *scene) {
    this->scene = scene;
    if(this->getGameObjectType() == "Sprite2D") {

        this->scene->addToRenderer(((Sprite2D*)this));
    }
    if(this->getGameObjectType() == "Collision") {
        this->scene->addToSceneCollision(((Collision*)this));
    }
    for (int i = 0; i < children.size(); i++) {
        children[i]->setScene(scene);
    }
}

glm::vec2 GameObject::getPosition() {
    return this->globalPosition;
}
glm::vec2 GameObject::getScale() {
    return this->Scale;
}

std::vector<GameObject*> GameObject::getChildren() {
    return children;
}

std::string GameObject::getGameObjectType() {
    return GameObjectType;
}
GameObject* GameObject::getParent() {
    return parent;
}

void GameObject::setPosition(glm::vec2 Position) {
    this->localPosition = Position;
    if(this->parent != NULL) {
        this->globalPosition = this->localPosition + this->parent->globalPosition;

    }

    for (int i = 0; i < children.size(); ++i) {
        children[i]->globalPosition = this->globalPosition + children[i]->localPosition;
    }
}

void GameObject::setScale(glm::vec2 Scale) {
    this->Scale = Scale;
}