#include "Scene.h"

Scene::Scene()
{
    renderer = RENDERMANAGER.GetRenderer();
	spawner = new Spawner();
}

std::string Scene::OnExit()
{
    isFinished = false;
    return nextScene;
}

void Scene::Update(float dt)
{
	for (Object* o : objects)
	{
		o->Update(dt);
	}

	for (Object* o : ui)
	{
		o->Update(dt);
	}

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