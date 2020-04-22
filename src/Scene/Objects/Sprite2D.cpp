//
// Created by Lukas on 2020-04-09.
//

#include <iostream>
#include "Sprite2D.h"
#include "../../Renderer/SpriteRenderer.h"

Sprite2D::Sprite2D(Texture &texture, glm::vec2 position, glm::vec2 size, GLfloat rotation, glm::vec3 color) : sprite(texture), Color(color), GameObject(position, size, rotation, "Sprite2D") {}

void Sprite2D::setSprite(Texture &sprite) {
    this->sprite = sprite;
}

void Sprite2D::setColor(glm::vec3 Color) {
    this->Color = Color;
}

void Sprite2D::Render(SpriteRenderer &renderer) {
    renderer.DrawSprite(this->sprite, this->Position, this->Size, this->Rotation, this->Color);
}