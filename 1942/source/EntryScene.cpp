#include "EntryScene.h"

EntryScene::EntryScene()
{
	Object* presentation = new Presentation(Vector2(200, 200));
	objects.push_back(presentation);
	int id = AUDIOMANAGER.LoadClip("resources/audios/INTRO.wav");
	AUDIOMANAGER.PlayClip(id);
}

void EntryScene::OnEnter()
{
}

void EntryScene::Update(float dt)
{
	actualTime += dt;
	for (Object* o : ui)
	{
		o->Update(dt);
	}
	for (Object* o : objects)
	{
		o->Update(dt);
	}

	if (actualTime > timeDuration)
	{
		isFinished = true;
		nextScene = "MainMenu";
	}
}

void EntryScene::Render()
{
	for (Object* o : ui)
	{
		o->Render();
	}
	for (Object* o : objects)
	{
		o->Render();
	}
}
