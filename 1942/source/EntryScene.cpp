#include "EntryScene.h"

EntryScene::EntryScene()
{
	Object* presentation = new Presentation(Vector2(200, 200));
	objects.push_back(presentation);
	int id = AUDIOMANAGER.LoadClip("resources/audios/INTRO.wav");
	AUDIOMANAGER.PlayClip(id);
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i;
	std::ofstream myFileRankings;
	myFileRankings.open("config/rankingsSave.dat", std::ios::out | std::ios::binary);
	if (!myFileRankings.is_open())
	{
		std::cout << "cant open file" << std::endl;
		return;
	}
	myFileRankings.write(reinterpret_cast<char*>(&a), sizeof(int) * 10);
	myFileRankings.close();
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
