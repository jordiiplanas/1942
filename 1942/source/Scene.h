<<<<<<< HEAD:SDL3/source/Scene.h
﻿#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "TextRenderer.h"
#include "Spawner.h"
#include "InputManager.h"
#include "AudioManager.h"

class Scene
{
protected:
    std::vector<Object*> ui;
    std::vector<Object*> objects;

    bool isFinished;
    std::string nextScene;

    SDL_Renderer* renderer;

public:
    Scene();
    virtual void OnEnter() = 0;
    virtual std::string OnExit();
    virtual void Update(float dt);
    virtual void Render();

    inline void AddObject(Object* o) {	objects.push_back(o); }

    inline bool IsFinished() { return isFinished; }

};
=======
﻿#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "TextRenderer.h"
#include "Spawner.h"
#include "InputManager.h"
#include "AudioManager.h"

class Scene
{
protected:
    std::vector<Object*> ui;
    std::vector<Object*> objects;

    bool isFinished;
    std::string nextScene;

    SDL_Renderer* renderer;

public:
    Scene();
    virtual void OnEnter() = 0;
    virtual std::string OnExit();
    virtual void Update(float dt);
    virtual void Render();

    inline void AddObject(Object* o) {	objects.push_back(o); }

    inline bool IsFinished() { return isFinished; }

};
>>>>>>> main:1942/source/Scene.h
