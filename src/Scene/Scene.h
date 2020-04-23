//
// Created by Lukas on 2020-04-08.
//

#ifndef FLAPPYBIRD_SCENE_H
#define FLAPPYBIRD_SCENE_H

#include <Scene/Objects/Collision/Collision.h>
#include <Scene/Objects/Camera.h>
#include "Objects/GameObject.h"
#include "Renderer/SpriteRenderer.h"
#include "Objects/Sprite2D.h"

class Scene {
public:

    Scene(GameObject &root);
    void renderScene(SpriteRenderer &renderer);
    GameObject &root;
    void addToRenderer(Sprite2D *sprite);
    void setCameraActive(Camera *camera);
    void addToSceneCollision(Collision *collision);
    void CheckCollision();
private:
    glm::mat4 projection;
    Camera *activeCamera;
    std::vector<Sprite2D*> sceneRenderer;
    std::vector<Collision*> sceneCollisions;
};


#endif //FLAPPYBIRD_SCENE_H
