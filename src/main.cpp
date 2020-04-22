#define GLEW_STATIC
#include "gl/glew.h"
#include <GLFW/glfw3.h>
#include "Display/WindowHandler.h"
#include "Game.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

WindowHandler *windowHandler;

GLFWwindow *Window;

const GLuint SCREEN_WIDTH = 800;

const GLuint SCREEN_HEIGHT = 600;

Game gameEngine(SCREEN_WIDTH, SCREEN_HEIGHT);

int main() {
    windowHandler = new WindowHandler(SCREEN_WIDTH, SCREEN_HEIGHT);
    Window = windowHandler->getWindow();
    glewInit();
    glGetError();

    glfwSetKeyCallback(Window, key_callback);

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    gameEngine.Init();

    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;

    while (!glfwWindowShouldClose(Window))
    {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        //gameEngine.ProcessInput(deltaTime);

        //gameEngine.Update();

        glClearColor(0.4f, 0.5f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        gameEngine.Render();

        glfwSwapBuffers(Window);
    }
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
