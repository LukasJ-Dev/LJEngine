//
// Created by Lukas on 2020-04-08.
//

#ifndef FLAPPYBIRD_SCENE_H
#define FLAPPYBIRD_SCENE_H

#include "Objects/GameObject.h"
#include "Renderer/SpriteRenderer.h"
#include "Objects/Sprite2D.h"

class Scene {
public:

    Scene(GameObject &root);
    void renderScene(SpriteRenderer &renderer);
    GameObject &root;
    void addToRenderer(Sprite2D *sprite);
private:
    std::vector<Sprite2D*> sceneRenderer;
    void getChilds(SpriteRenderer &renderer, GameObject *gameObject);
};


#endif //FLAPPYBIRD_SCENE_H
