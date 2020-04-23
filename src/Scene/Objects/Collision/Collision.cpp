//
// Created by Lukas on 2020-04-22.
//

#include <iostream>
#include "Collision.h"

Collision::Collision(glm::vec2 position, glm::vec2 scale, GLfloat rotation, glm::vec2 size) : size(size), GameObject(position, scale, rotation, "Collision") {

}

bool Collision::collideWith(Collision *collision) {
    glm::vec2 c1Pos = this->getPosition();
    glm::vec2 c2Pos = collision->getPosition();

    glm::vec2 c1Size = this->getSize();
    glm::vec2 c2Size = collision->getSize();

    if(
            c2Pos.x - (c2Size.x/2) < c1Pos.x + (c1Size.x/2) &&
            c1Pos.x - (c1Size.x/2) < c2Pos.x + (c2Size.x/2)) {
        this->onCollide(collision);
        collision->onCollide(this);
        return true;
    }
    if(
            c2Pos.y - (c2Size.y/2) > c1Pos.y + (c1Size.y/2) &&
            c1Pos.y - (c1Size.y/2) > c2Pos.y + (c2Size.y/2)
            ) {
        this->onCollide(collision);
        collision->onCollide(this);
        return true;
    }
    return false;
}

glm::vec2 Collision::getSize() {
    return size;
}

void Collision::onCollide(Collision *collision) {
    std::cout << this->getPosition().x;
    std::cout << " COLLIDED ";
    std::cout << collision->getPosition().x << std::endl;
}