//
// Created by Lukas on 2020-04-08.
//

#ifndef FLAPPYBIRD_GAME_H
#define FLAPPYBIRD_GAME_H

#include "gl/glew.h"
#include <GLFW/glfw3.h>

class Game {
public:
    GLuint Width, Height;
    Game(GLuint width, GLuint height);
    void Init();
    void ProcessInput(GLfloat dt);
    void Update();

    void Render();
};


#endif //FLAPPYBIRD_GAME_H
