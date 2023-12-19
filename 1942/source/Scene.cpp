<<<<<<< HEAD:SDL3/source/Scene.cpp
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
=======
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
>>>>>>> main:1942/source/Scene.cpp
}