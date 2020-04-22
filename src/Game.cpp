//
// Created by Lukas on 2020-04-08.
//

#include "Game.h"
#include "Manager/ResourceManager.h"
#include "Scene/Scene.h"
#include "Scene/Objects/Sprite2D.h"

Scene *world;

Sprite2D *Car;
Sprite2D *LJ;
Sprite2D *Face;

SpriteRenderer *spriteRenderer;

Game::Game(GLuint width, GLuint height)
    : Width(width), Height(height) {

}

void Game::Init() {
    ResourceManager::LoadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.frag", nullptr, "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(Width), static_cast<GLfloat>(Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    ResourceManager::LoadTexture("resources/textures/car.png", GL_TRUE, "car");
    ResourceManager::LoadTexture("resources/textures/awesomeface.png", GL_TRUE, "face");
    ResourceManager::LoadTexture("resources/textures/LJ.png", GL_TRUE, "LJ");

    spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    GameObject rootObject = GameObject(glm::vec2(0,0),glm::vec2(1,1),0);

    world = new Scene(rootObject);

    Car = new Sprite2D(ResourceManager::GetTexture("car"), glm::vec2(100, 100), glm::vec2(5, 5), 0);
    Face = new Sprite2D(ResourceManager::GetTexture("face"), glm::vec2(500, 300), glm::vec2(1, 1), 0);
    LJ = new Sprite2D(ResourceManager::GetTexture("LJ"), glm::vec2(700, 100), glm::vec2(1, 1), 0);

    rootObject.attachChild(Car);
    rootObject.attachChild(Face);
    rootObject.attachChild(LJ);
}

void Game::Render() {
    world->renderScene(*spriteRenderer);
}