//
// Created by Lukas on 2020-04-08.
//

#include <iostream>
#include "Scene.h"

#include <typeinfo>

#include "../Scene/Objects/Sprite2D.h"

Scene::Scene(GameObject &root) : root(root) {
    root.setScene(this);
}

void Scene::renderScene(SpriteRenderer &renderer) {
    for(int i = 0; i < sceneRenderer.size(); i++) {
        sceneRenderer[i]->Render(renderer);
    }
    //getChilds(renderer, &root);
}

void Scene::addToRenderer(Sprite2D *sprite) {
    sceneRenderer.push_back(sprite);
}

void Scene::getChilds(SpriteRenderer &renderer, GameObject *gameObject) {
    /*std::vector<GameObject*> children = gameObject->getChildren();
    for(int i = 0; i < children.size(); i++) {
        if(typeid(children[i]) == typeid(Sprite2D)) {
            ((Sprite2D*)children[i])->Render(renderer);
        }
        if(children[i]->getChildren().size() < 0) {
            getChilds(renderer, children[i]);
        }
    }*/
}