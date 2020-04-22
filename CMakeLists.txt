cmake_minimum_required(VERSION 3.15)
project(LJEngine)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/glfw-3.3.2)
add_subdirectory(lib/glew-2.1.0/build/cmake)
include_directories(lib/glfw-3.3.2/include)
include_directories(lib/glew-2.1.0/include)
include_directories(lib/soil/include)
include_directories(lib/glm)

include_directories(src)

add_library(SOIL lib/soil/src/soil.c lib/soil/src/image_dxt.c lib/soil/src/image_helper.c lib/soil/src/stb_image_aug.c)

add_executable(LJEngine src/main.cpp src/Display/WindowHandler.cpp src/Display/WindowHandler.h src/Game.cpp src/Game.h src/Scene/Scene.cpp src/Scene/Scene.h src/Scene/Objects/GameObject.cpp src/Scene/Objects/GameObject.h src/Scene/Objects/Sprite2D.cpp src/Scene/Objects/Sprite2D.h src/Renderer/Texture.cpp src/Renderer/Texture.h src/Manager/ResourceManager.cpp src/Manager/ResourceManager.h src/Renderer/Shader.cpp src/Renderer/Shader.h src/Renderer/SpriteRenderer.cpp src/Renderer/SpriteRenderer.h)

target_link_libraries(LJEngine SOIL glfw glew)