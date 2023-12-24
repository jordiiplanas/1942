#include "GameplayScene.h"

void GameplayScene::OnEnter()
{
    nextScene = "MainMenu";
    player = new Player(Vector2(250, 350));
    
    AUDIOMANAGER.PlayMusic(AUDIOMANAGER.LoadMusic("resources/audios/musiquita.mp3"));
    Vector2 initialPos = Vector2(0, -64);
    Vector2 limitsPos = Vector2(512, 512);
    int counter = 0;
    while (initialPos.y < limitsPos.y)
    {
        while (initialPos.x < limitsPos.x)
        {
            background.push_back(new Background(Vector2(32, 32), 10));
            background.back()->SetPosition(initialPos);
			initialPos.x += 32;
		}
		initialPos.x = 0;
		initialPos.y += 32;
	}
    objects.push_back(player);
    objects.push_back(new SmallNormalPlane(STRAIGHT, player->GetTransform(), true));
    objects.push_back(new SmallRedPlane(player->GetTransform(), true, true));
    objects.push_back(new MediumYellowPlane(player->GetTransform(), false, 300));
    objects.push_back(new WhitePowerUp(*player));
    objects.push_back(new BigGreenPlane(player->GetTransform()));
}

void GameplayScene::Update(float dt)
{
	isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);
    
    for (Object* o : background)
	{
		o->Update(dt);
	}

    for (Object* o : objects)
    {
        if (o == nullptr)
        {
            objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
			continue;
        }

        if (!o->IsPendingDestroy())
        {                   
            o->Update(dt);            
            continue;
        }

        if (dynamic_cast<WhitePowerUp*>(o))
        {
            if (dynamic_cast<WhitePowerUp*>(o)->isActive)
            {
                dynamic_cast<WhitePowerUp*>(o)->isActive = false;
                for (Object* o : objects)
                {
                    if (dynamic_cast<Enemy*>(o))
                    {
                        o->Destroy();
                    }
                }
            }
        }
        
        if (o == player)
			player = nullptr;

        if (dynamic_cast<SupportPlane*>(o))
        {
            player->DisableSupportPlane(o);
        }
        objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
        delete o;
    }

    for (Object* o : objects)
    {
        for (Object* a : objects)
        {
            if (o == a)
                continue;
            if (dynamic_cast<Player*>(o) && dynamic_cast<SupportPlane*>(a) ||
                dynamic_cast<Player*>(a) && dynamic_cast<SupportPlane*>(o) ||
                dynamic_cast<SupportPlane*>(o) && dynamic_cast<SupportPlane*>(a)
                )
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

   

    
}

void GameplayScene::Render()
{
	for (Object* o : background)
	{
		o->Render(renderer);
	}
	for (Object* o : objects)
	{
		o->Render(renderer);
	}
    for (Object* o : ui)
	{
        o->Render(renderer);
	}

}
