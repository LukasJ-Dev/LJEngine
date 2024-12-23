//
// Created by Lukas on 2020-04-13.
//

#include "ResourceManager.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include <SOIL/SOIL.h>

std::map<std::string, Texture> ResourceManager::Sprites;
std::map<std::string, Shader> ResourceManager::Shaders;

Texture ResourceManager::LoadTexture(std::string filePath, GLboolean alpha, std::string name)
{
    Sprites[name] = loadTextureFromFile(filePath.c_str(), alpha);
    return Sprites[name];
}

Texture ResourceManager::loadTextureFromFile(const GLchar *file, GLboolean alpha)
{
    // Create Texture object
    Texture sprite;
    if (alpha)
    {
        sprite.Internal_Format = GL_RGBA;
        sprite.Image_Format = GL_RGBA;
    }
    // Load image
    int width, height;
    unsigned char* image = SOIL_load_image(file, &width, &height, 0, sprite.Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
    // Now generate texture
    sprite.Generate(width, height, image);
    // And finally free image data
    SOIL_free_image_data(image);
    return sprite;
}

Texture ResourceManager::GetTexture(std::string name)
{
    return Sprites[name];
}

Shader ResourceManager::LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name)
{
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
    return Shaders[name];
}

Shader ResourceManager::loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile)
{
    // 1. Retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {
        // Open files
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
        std::stringstream vShaderStream, fShaderStream;
        // Read file's buffer contents into streams
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        // close file handlers
        vertexShaderFile.close();
        fragmentShaderFile.close();
        // Convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        // If geometry shader path is present, also load a geometry shader
        if (gShaderFile != nullptr)
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const GLchar *vShaderCode = vertexCode.c_str();
    const GLchar *fShaderCode = fragmentCode.c_str();
    const GLchar *gShaderCode = geometryCode.c_str();
    // 2. Now create shader object from source code
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
    return shader;
}