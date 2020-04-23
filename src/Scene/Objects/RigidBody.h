//
// Created by Lukas on 2020-04-22.
//

#ifndef LJENGINE_RIGIDBODY_H
#define LJENGINE_RIGIDBODY_H


#include "GameObject.h"

class RigidBody : public GameObject {
public:
    RigidBody(glm::vec2 position, glm::vec2 scale, GLfloat rotation);

    void Move(glm::vec2 velocity);
};


#endif //LJENGINE_RIGIDBODY_H
