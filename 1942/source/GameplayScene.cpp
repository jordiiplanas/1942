#include "GameplayScene.h"

void GameplayScene::OnEnter()
{
    nextScene = "MainMenu";
    player = new Player(Vector2(250, 350));
    
    Vector2 initialPos = Vector2(0, -64);
    Vector2 limitsPos = Vector2(512, 512);
    int counter = 0;
    while (initialPos.y < limitsPos.y)
    {
        while (initialPos.x < limitsPos.x)
        {
			objects.push_back(new Background(Vector2(32, 32), 10));
			objects.back()->SetPosition(initialPos);
			initialPos.x += 32;
		}
		initialPos.x = 0;
		initialPos.y += 32;
	}

    objects.push_back(player);
    objects.push_back(new Enemy(Vector2(250, 50)));

}

void GameplayScene::Update(float dt)
{
	isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);

 
    for (Object* o : objects)
    {
        if (!o->IsPendingDestroy())
        {
            o->Update(dt);
            continue;
        }
        objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
        if (o == player)
			player = nullptr;
        delete o;
    }

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

    if (SPAWNER.CanSpawn())
    {
        objects.push_back(SPAWNER.SpawnObject());
    }

    isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, KeyState::PRESSED);

   /* sfxID = AUDIOMANAGER.LoadClip("resources/audios/rave.wav");
   AUDIOMANAGER.FreeClip(sfxID);*/

    
}
