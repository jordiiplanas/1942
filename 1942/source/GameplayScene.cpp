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
            background.push_back(new Background(Vector2(32, 32), 20));
            background.back()->SetPosition(initialPos);
			initialPos.x += 32;
		}
		initialPos.x = 0;
		initialPos.y += 32;
	}
    Wave wave1 = Wave(A, 0.5, 10);
    Wave wave2 = Wave(B, 0.3, 10);
    Wave wave3 = Wave(C, 0.06, 10);
    Wave wave4 = Wave(D, 1, 10);
    Wave wave5 = Wave(E, 2, 10);
    
    waveIndex = 0;
    SPAWNER.InsertObject(player);
    waves.push_back(wave1);
    waves.push_back(wave2);
    waves.push_back(wave3);
    waves.push_back(wave4);
    waves.push_back(wave5);

}

void GameplayScene::Update(float dt)
{
	isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);
    
    for (Object* o : background)
	{
		o->Update(dt);
	}
    
    if (!waves[waveIndex].IsFinished())
	{
        waves[waveIndex].Update(dt, player->GetTransform());
	}
   else
    {
	    waveIndex++;
	    if (waveIndex >= waves.size())
	    {
		    waveIndex = 0;
	    }
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

       /* if (dynamic_cast<WhitePowerUp*>(o))
        {
            if (dynamic_cast<WhitePowerUp*>(o)->isActive)
            {
                dynamic_cast<WhitePowerUp*>(o)->isActive = false;
                for (Object* o : objects)
                {
                    if (dynamic_cast<EnemyPlane*>(o))
                    {
                        o->Destroy();
                    }
                }
            }
        }*/
        
        if (o == player)
			player = nullptr;

       if (dynamic_cast<SupportPlane*>(o))
       {
            player->DisableSupportPlane(o);
       }

       if (dynamic_cast<EnemyPlane*>(o))
       {
           
            if (rand() % 3 == 0)
            {
                WhitePowerUp* powerUp = new WhitePowerUp(*player);
                powerUp->SetPosition(o->GetTransform()->position);
                SPAWNER.InsertObject(powerUp);
            }
            else if (rand() % 3 == 1)
			{
                GrayPowerUp* powerUp = new GrayPowerUp(*player);
                powerUp->SetPosition(o->GetTransform()->position);
                SPAWNER.InsertObject(powerUp);
			}
			else if (rand() % 3 == 2)
			{
                GreenPowerUp* powerUp = new GreenPowerUp(*player);
                powerUp->SetPosition(o->GetTransform()->position);
                SPAWNER.InsertObject(powerUp);
			}
           
       }

        objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
        o = nullptr;
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
