//
// Created by Lukas on 2020-04-08.
//

#ifndef FLAPPYBIRD_WINDOWHANDLER_H
#define FLAPPYBIRD_WINDOWHANDLER_H

#include "gl/glew.h"
#include <GLFW/glfw3.h>

class WindowHandler {
public:
    WindowHandler(GLuint width, GLuint height);
    GLFWwindow* getWindow();
};


#endif //FLAPPYBIRD_WINDOWHANDLER_H
