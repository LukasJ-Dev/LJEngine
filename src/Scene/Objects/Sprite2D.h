//
// Created by Lukas on 2020-04-09.
//

#ifndef FLAPPYBIRD_SPRITE2D_H
#define FLAPPYBIRD_SPRITE2D_H


#include "GameObject.h"
#include "Renderer/Texture.h"
#include "Renderer/Shader.h"
#include "Renderer/SpriteRenderer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Sprite2D : public GameObject {
private:
    Texture sprite;
    GLuint quadVAO;
    glm::vec3 Color;

public:
    Sprite2D(Texture &texture, glm::vec2 position, glm::vec2 size, GLfloat rotation, glm::vec3 color = glm::vec3(1.0f));
    ~Sprite2D();
    void Render(SpriteRenderer &renderer);
    void setSprite(Texture &sprite);
    void setColor(glm::vec3 Color);
};


#endif //FLAPPYBIRD_SPRITE2D_H
