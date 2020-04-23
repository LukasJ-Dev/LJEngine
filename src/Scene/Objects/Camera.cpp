//
// Created by Lukas on 2020-04-22.
//

#include "Camera.h"

Camera::Camera(glm::vec2 Position, glm::vec2 Scale, GLfloat Rotation, glm::vec2 Size) : Size(Size), GameObject(Position, Scale, Rotation, "Camera"){}

glm::vec2 Camera::getSize() {
    return this->Size;
}

void Camera::setActive() {

}