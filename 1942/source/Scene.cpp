#include "Scene.h"

Scene::Scene()
{
    renderer = RENDERMANAGER.GetRenderer();

}

std::string Scene::OnExit()
{
    isFinished = false;
    return nextScene;
}

void Scene::Update(float dt)
{
    //Spawning

    //Destroying

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
        o->Render();
    }

    for (Object* o : ui)
    {
        o->Render();
    }
}