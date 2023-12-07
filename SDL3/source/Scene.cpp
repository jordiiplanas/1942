#include "Scene.h"

Scene::Scene()
{
    renderer = RENDERMANAGER.GetRenderer();
	spawner = new Spawner();
}

void Scene::Render()
{
    for (Object* o : objects)
    {
        o->Render(renderer);
    }

    for (Object* o : ui)
    {
        o->Render(renderer);
    }
}