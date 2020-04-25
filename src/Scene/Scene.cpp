//
// Created by Lukas on 2020-04-08.
//

#include <iostream>
#include "Scene.h"

#include <typeinfo>
#include <Manager/ResourceManager.h>

#include "../Scene/Objects/Sprite2D.h"

Scene::Scene(GameObject &root) : root(root) {
    root.setScene(this);
}

void Scene::renderScene(SpriteRenderer &renderer) {
    glm::vec2 cameraSize = activeCamera->getSize();
    glm::vec2 cameraPos = activeCamera->getPosition();

    projection = glm::ortho(
            static_cast<GLfloat>(-(cameraSize.x/2) + cameraPos.x),
            static_cast<GLfloat>(cameraSize.x-(cameraSize.x/2) + cameraPos.x ),
            static_cast<GLfloat>(cameraSize.y-(cameraSize.y/2) + cameraPos.y ),
            static_cast<GLfloat>(-(cameraSize.y/2) + cameraPos.y),
            -1.0f, 1.0f);

    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    for(int i = 0; i < sceneRenderer.size(); i++) {
        sceneRenderer[i]->Render(renderer);
    }
}

void Scene::addToRenderer(Sprite2D *sprite) {
    sceneRenderer.push_back(sprite);
}

void Scene::setCameraActive(Camera *camera) {
    this->activeCamera = camera;
}

void Scene::addToSceneCollision(Collision *collision) {
    sceneCollisions.push_back(collision);
}

void Scene::CheckCollision() {
    for(int i = 0; i < sceneCollisions.size(); i++) {
        for(int c = i+1; c < sceneCollisions.size(); c++) {
            //std::cout << sceneCollisions[i]->collideWith(sceneCollisions[c]) << std::endl;


        }
    }
}