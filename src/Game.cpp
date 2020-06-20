//
// Created by Lukas on 2020-04-08.
//

#include <Scene/Objects/RigidBody.h>
#include <iostream>
#include <Manager/SceneLoader.h>
#include "Manager/ScriptManager/LuaReflection.h"
#include "Game.h"
#include "Manager/ResourceManager.h"
#include "Scene/Scene.h"
#include "Scene/Objects/Sprite2D.h"

Scene *world;

SpriteRenderer *spriteRenderer;

glm::mat4 projection;

std::vector<lua_State*> lState;

Game::Game(GLuint width, GLuint height)
    : Width(width), Height(height) {

}

std::string Game::getGamePath() {
    return gamePath;
}

void Game::Init() {
    std::ifstream configFile(gamePath + "config.json");
    json configJSON;
    configFile >> configJSON;
    std::cout << configJSON["gameName"] << std::endl;

    ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");

    projection = glm::ortho(0.0f, static_cast<GLfloat>(Width), static_cast<GLfloat>(Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    for(int i = 0; i < configJSON["resources"]["textures"].size(); i++) {
        ResourceManager::LoadTexture(
                gamePath + "resources/textures/" + configJSON["resources"]["textures"][i]["path"].get<std::string>(),
                GL_TRUE, configJSON["resources"]["textures"][i]["name"]);

        std::cout << gamePath + "resources/textures/" + configJSON["resources"]["textures"][i]["path"].get<std::string>() << std::endl;
    }

    spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    world = SceneLoader::loadScene(gamePath + "scenes/" + configJSON["conf"]["mainScene"].get<std::string>(), this);

    world->setCameraActive(SceneLoader::getCamera());

    lState = SceneLoader::getState();

    for(int i = 0; i < lState.size(); i++) {
        LuaReflection::CallFunctionFromScript(lState.at(i), "init");
    }
}

void Game::Render() {
    world->renderScene(*spriteRenderer);
}

void Game::ProcessInput(GLfloat dt) {}

void Game::Update() {
    world->CheckCollision();

    for(int i = 0; i < lState.size(); i++) {
        LuaReflection::CallFunctionFromScript(lState.at(i), "update");
    }
};

void Game::Fixed_Update(GLfloat delta) {
    //carBody->Move(glm::vec2(-100,20)*delta);
    //Car->Rotation+=1*delta;
}