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
    virtual void Update(float dt)
    {
        //destroy
        for (int i = objects.size() - 1; i >= 0; i--)
        {
            if (objects[i]->IsPendingDestroy())
            {
                delete objects[1];
                objects.erase(objects.begin() + 1);
            }
                
        }
        for (int i = ui.size() - 1; i >= 0; i--)
        {
            if (ui[i]->IsPendingDestroy())
            {
                delete ui[1];
                ui.erase(ui.begin() + 1);
            }
        }
        //spawning
        for (Object* o : objects)
        {
            o->Update(dt);
        }
        for (Object* gameUI : ui)
        {
            gameUI->Update(dt);
        }
    }
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
