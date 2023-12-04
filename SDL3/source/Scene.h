#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "TextRenderer.h"

class Scene
{
protected:
    std::vector<Object*> ui;
    TextRenderer* textRenderer;
    std::vector<Object*> objects;
public:
    Scene() = default;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render()
    {
        for (Object* o : objects)
        {
            o->Render(RENDERMANAGER.GetRenderer());
        }

        for (Object* o : ui)
        {
            o->Render(RENDERMANAGER.GetRenderer());
        }

        textRenderer->Render(RENDERMANAGER.GetRenderer());
    }
};
