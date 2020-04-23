//
// Created by Lukas on 2020-04-22.
//

#include "RigidBody.h"


RigidBody::RigidBody(glm::vec2 position, glm::vec2 scale, GLfloat rotation) : GameObject(position, scale, rotation, "RigidBody") {}

void RigidBody::Move(glm::vec2 velocity) {
    this->setPosition(this->localPosition + velocity);
}