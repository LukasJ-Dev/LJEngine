//
// Created by Lukas on 2020-04-22.
//

#ifndef LJENGINE_CAMERA_H
#define LJENGINE_CAMERA_H


#include "GameObject.h"

class Camera : public GameObject {
private:
    glm::vec2 Size;
public:
    Camera(glm::vec2 Position, glm::vec2 Scale, GLfloat Rotation, glm::vec2 Size);
    glm::vec2 getSize();
    void setActive();
};


#endif //LJENGINE_CAMERA_H
