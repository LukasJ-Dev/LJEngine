//
// Created by Lukas on 2020-04-13.
//

#ifndef FLAPPYBIRD_RESOURCEMANAGER_H
#define FLAPPYBIRD_RESOURCEMANAGER_H

#include <map>
#include <string>

#include "gl/glew.h"
#include "Renderer/Texture.h"
#include "Renderer/Shader.h"

class ResourceManager {
public:
    static std::map<std::string, Texture> Sprites;
    static std::map<std::string, Shader> Shaders;

    static Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);

    static Shader GetShader(std::string name);

    static Texture LoadTexture(std::string file, GLboolean alpha, std::string name);

    static Texture GetTexture(std::string name);
private:
    ResourceManager() { }

    static Texture loadTextureFromFile(const GLchar *file, GLboolean alpha);

    static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

};


#endif //FLAPPYBIRD_RESOURCEMANAGER_H
