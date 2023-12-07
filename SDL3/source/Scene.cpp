#include "Scene.h"

Scene::Scene()
{
	spawner = new Spawner();
}

void Scene::Render()
{
    for (Object* o : objects)
    {
        o->Render(RENDERMANAGER.GetRenderer());
    }

    for (Object* o : ui)
    {
        o->Render(RENDERMANAGER.GetRenderer());
    }
}