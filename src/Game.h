//
// Created by Lukas on 2020-04-08.
//

#ifndef FLAPPYBIRD_GAME_H
#define FLAPPYBIRD_GAME_H

#include "gl/glew.h"
#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

class Game {
private:
    std::string gamePath = "Games/testGame/";
public:
    std::string getGamePath();
    GLuint Width, Height;
    Game(GLuint width, GLuint height);
    void Init();
    void ProcessInput(GLfloat delta);
    void Update();
    void Fixed_Update(GLfloat delta);

    void Render();
};


#endif //FLAPPYBIRD_GAME_H
