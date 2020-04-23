//
// Created by Lukas on 2020-04-08.
//

#include <Scene/Objects/RigidBody.h>
#include <iostream>
#include "Game.h"
#include "Manager/ResourceManager.h"
#include "Scene/Scene.h"
#include "Scene/Objects/Sprite2D.h"

Scene *world;

GameObject *rootObject;

RigidBody *carBody;

Sprite2D *Car;
Sprite2D *LJ;
Sprite2D *Face;

Collision *collision1;
Collision *collision2;
Collision *collision3;

Camera *camera;

SpriteRenderer *spriteRenderer;

glm::mat4 projection;

Game::Game(GLuint width, GLuint height)
    : Width(width), Height(height) {

}

void Game::Init() {
    ResourceManager::LoadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.frag", nullptr, "sprite");

    projection = glm::ortho(0.0f, static_cast<GLfloat>(Width), static_cast<GLfloat>(Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    ResourceManager::LoadTexture("resources/textures/car.png", GL_TRUE, "car");
    ResourceManager::LoadTexture("resources/textures/awesomeface.png", GL_TRUE, "face");
    ResourceManager::LoadTexture("resources/textures/LJ.png", GL_TRUE, "LJ");

    spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    rootObject = new GameObject(glm::vec2(0,0),glm::vec2(1,1),0);

    camera = new Camera(glm::vec2(0,0),glm::vec2(1,1),0,glm::vec2(Width, Height));

    world = new Scene(*rootObject);

    carBody = new RigidBody(glm::vec2(700,100),glm::vec2(1,1),0);

    rootObject->attachChild(carBody);
    Car = new Sprite2D(ResourceManager::GetTexture("car"), glm::vec2(0, 0), glm::vec2(5, 5), 0);
    Face = new Sprite2D(ResourceManager::GetTexture("face"), glm::vec2(100, 100), glm::vec2(1, 1), 0);
    LJ = new Sprite2D(ResourceManager::GetTexture("LJ"), glm::vec2(-200, 0), glm::vec2(1, 1), 0);

    collision1 = new Collision(glm::vec2(0,0),glm::vec2(1,1), 0, glm::vec2(80,40));
    collision2 = new Collision(glm::vec2(0,0),glm::vec2(1,1), 0, glm::vec2(128,128));
    collision3 = new Collision(glm::vec2(0,0),glm::vec2(1,1), 0, glm::vec2(256,256));

    carBody->attachChild(Car);
    carBody->attachChild(camera);
    carBody->attachChild(collision1);
    rootObject->attachChild(Face);
    rootObject->attachChild(LJ);
    LJ->attachChild(collision2);
    Face->attachChild(collision3);

    world->setCameraActive(camera);
}

void Game::Render() {
    world->renderScene(*spriteRenderer);
}

void Game::ProcessInput(GLfloat dt) {}

void Game::Update() {
    world->CheckCollision();
};

void Game::Fixed_Update(GLfloat delta) {
    carBody->Move(glm::vec2(-100,20)*delta);
    //Car->Rotation+=1*delta;
}