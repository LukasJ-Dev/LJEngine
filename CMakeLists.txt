cmake_minimum_required(VERSION 3.15)
project(LJEngine)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/glfw-3.3.2)
add_subdirectory(lib/glew-2.1.0/build/cmake)
add_subdirectory(lib/json-develop)
include_directories(lib/glfw-3.3.2/include)
include_directories(lib/glew-2.1.0/include)
include_directories(lib/json-develop/single_include)
include_directories(lib/soil/include)
include_directories(lib/glm)
include_directories(lib/lua/include)

link_directories(lib/lua)

include_directories(src)

add_library(SOIL lib/soil/src/soil.c lib/soil/src/image_dxt.c lib/soil/src/image_helper.c lib/soil/src/stb_image_aug.c)
#set(CMAKE_CXX_LINK_LIBRARY_FILE_FLAG  ${CMAKE_CXX_LINK_LIBRARY_FILE_FLAG} /Zm10)
add_executable(LJEngine src/main.cpp src/Display/WindowHandler.cpp src/Display/WindowHandler.h src/Game.cpp src/Game.h src/Scene/Scene.cpp src/Scene/Scene.h src/Scene/Objects/GameObject.cpp src/Scene/Objects/GameObject.h src/Scene/Objects/Sprite2D.cpp src/Scene/Objects/Sprite2D.h src/Renderer/Texture.cpp src/Renderer/Texture.h src/Manager/ResourceManager.cpp src/Manager/ResourceManager.h src/Renderer/Shader.cpp src/Renderer/Shader.h src/Renderer/SpriteRenderer.cpp src/Renderer/SpriteRenderer.h src/Scene/Objects/RigidBody.cpp src/Scene/Objects/RigidBody.h src/Scene/Objects/Collision/Collision.cpp src/Scene/Objects/Collision/Collision.h src/Scene/Objects/Camera.cpp src/Scene/Objects/Camera.h src/Manager/SceneLoader.cpp src/Manager/SceneLoader.h src/Manager/ScriptManager/LuaReflection.cpp src/Manager/ScriptManager/LuaReflection.h src/Manager/ScriptManager/ScriptRegistrations.cpp src/Manager/ScriptManager/ScriptRegistrations.h src/Manager/KeyHandler.cpp src/Manager/KeyHandler.h)

find_package(RTTR CONFIG REQUIRED Core)
target_link_libraries(LJEngine SOIL glfw glew nlohmann_json lua53 RTTR::Core_Lib)