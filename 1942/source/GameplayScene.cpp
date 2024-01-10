#include "GameplayScene.h"

void GameplayScene::OnEnter()
{
    nextScene = "MainMenu";
    
    player = new Player(Vector2(250, 350));
    SPAWNER.InsertObject(player);

    AUDIOMANAGER.PlayMusic(AUDIOMANAGER.LoadMusic("resources/audios/musiquita.mp3"));
    
    Vector2 initialPos = Vector2(0, -64);
    Vector2 limitsPos = Vector2(512, 512);

    //BACKGROUND
    int counter = 0;
    while (initialPos.y < limitsPos.y)
    {
        while (initialPos.x < limitsPos.x)
        {
            background.push_back(new Background(Vector2(32, 32), 20));
            background.back()->SetPosition(initialPos);
			initialPos.x += 32;
		}
		initialPos.x = 0;
		initialPos.y += 32;
	}

    // WAVES
    Transform* transform = player->GetTransform();
    Wave* wave1 = new Wave(A, 0.5, 4, transform);
    wave1->SetInitialPosition(Vector2(300, 0));
    Wave* wave2 = new Wave(B, 0.5, 4, transform);
    wave2->SetInitialPosition(Vector2(-20, rand() % (450 - 50 + 1) + 50));
    Wave* wave3 = new Wave(C, 0.5, 2, transform);
    Wave* wave4 = new Wave(D, 1, 1, transform);
    Wave* wave5 = new Wave(E, 2, 3, transform);
    Wave* wave6 = new Wave(F, 3, 4, transform);
    waveIndex = 0;
    /*waves.push_back(wave1);
    waves.push_back(wave2);
    waves.push_back(wave3);
    waves.push_back(wave4);
    waves.push_back(wave5);
    waves.push_back(wave6);*/

    // UI
    scoreUi = new UiText("SCORE: 0", Vector2(60, 30));
    //ui.push_back(scoreUi);
}

void GameplayScene::Update(float dt)
{
    // INPUTS

    //TODO : Pause
	isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);
  
    // WAVES

    if (waves.size() > waveIndex)
    {
        if (!waves[waveIndex]->IsFinished())
        {
            waves[waveIndex]->Update(dt);
        }
        else
        {
            waveIndex++;
        }
    }

    // UPDATE OBJECTS

    for (Object* o : background)
	{
		o->Update(dt);
	}

    for (Object* o : objects)
    {
        if (o->IsPendingDestroy())
        {
            o->Update(dt);
            objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
            continue;
        }
        o->Update(dt);
        

    }

    for (Object* o : ui)
    {
        o->Update(dt);
    }
    scoreUi->ChangeText("SCORE: " + std::to_string(SCOREMANAGER.GetScore()));

    // COLLISIONS

    for (Object* o : objects)
    {
        for (Object* a : objects)
        {
            if (o == a)
                continue;

            if (o->GetRigidbody()->CheckCollision(a->GetRigidbody()))
                o->OnCollisionEnter(a);
        }
    }

    // SPAWN ELEMENTS

    if (SPAWNER.CanSpawn())
    {
        objects.push_back(SPAWNER.SpawnObject());
    }
}

void GameplayScene::Render()
{
	for (Object* o : background)
	{
		o->Render();
	}
	for (Object* o : objects)
	{
		o->Render();
	}
    for (Object* o : ui)
	{
        o->Render();
	}

}
