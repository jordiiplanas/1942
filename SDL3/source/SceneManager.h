#pragma once
#include <unordered_map>
#include <string>
#include "Scene.h"

#define SCENEMANAGER SceneManager::Instance()

class SceneManager {

    std::unordered_map<std::string, Scene*> scenes;

    Scene* currentScene;

    SceneManager() = default;
    SceneManager(SceneManager&) = delete;

    SceneManager& operator= (const SceneManager&) = delete;

public:
    static SceneManager& Instance()
    {
        static SceneManager sm;
        return sm;
    }

    inline bool AddScene(std::string name, Scene* scn)
    {
        if (scenes.find(name) == scenes.end()) 
        {
            scenes.emplace(name, scn);
            return true;
        }
        return false;
    }

    inline Scene* GetScene(std::string name)
    {
        if(scenes.find(name) != scenes.end())
            return scenes[name];
        return nullptr;
    }

    inline Scene* GetCurrentScene()
    {
        return currentScene;
    }

    inline bool SetCurrentScene(std::string name)
    {
        if (scenes.find(name) != scenes.end()) {
            currentScene = scenes[name];
            return true;
        }
        return false;
    }
};