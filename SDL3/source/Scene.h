#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "TextRenderer.h"
#include "Spawner.h"

class Scene
{
protected:
    std::vector<Object*> ui;
    TextRenderer* textRenderer;
    std::vector<Object*> objects;
    Spawner* spawner;

public:
    Scene();
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update(float dt) = 0;
    inline void AddObject(Object* o) {	objects.push_back(o); }
    virtual void Render();
};
