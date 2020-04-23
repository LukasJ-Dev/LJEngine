//
// Created by Lukas on 2020-04-08.
//

#include "WindowHandler.h"

#include "gl/glew.h"
#include <GLFW/glfw3.h>

GLFWwindow *window;

WindowHandler::WindowHandler(GLuint width, GLuint height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(width,height, "LJEngine 0.0.1", nullptr, nullptr);

    glfwMakeContextCurrent(window);
}

GLFWwindow* WindowHandler::getWindow() {
    return window;
}