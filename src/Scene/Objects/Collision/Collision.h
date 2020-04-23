//
// Created by Lukas on 2020-04-22.
//

#ifndef LJENGINE_COLLISION_H
#define LJENGINE_COLLISION_H


#include "gl/glew.h"
#include <glm/glm.hpp>
#include <vector>
#include <Scene/Objects/GameObject.h>

class Collision : public GameObject {
protected:
    glm::vec2 size;
public:
    Collision(glm::vec2 position, glm::vec2 scale, GLfloat rotation, glm::vec2 size);

    glm::vec2 Collision::getSize();
    bool collideWith(Collision *collision);
    void onCollide(Collision *collision);
};


#endif //LJENGINE_COLLISION_H
