#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{
    player = new Player(
        "resources/1942.png",
        Vector2(100, 64),
        Vector2(5, 6),
        Vector2(26, 16),
        renderer);
    
        
    player->GetRigidbody()->SetLinearDrag(5);
    player->SetPosition(Vector2(256, 256));
}

MainMenu::~MainMenu()
{

}

void MainMenu::OnEnter()
{

}

void MainMenu::OnExit()
{

}

void MainMenu::Update(float dt)
{
    for (Object* o : objects)
    {
        o->Update(dt);
        if (o->IsPendingDestroy()) 		
        {
			delete o;
            objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
		}
    }

    player->Update(dt);

    if (spawner->CanSpawn()) 
    { 
        objects.push_back(spawner->SpawnObject()); 
    }

    Vector2 inputForce = Vector2();

    if (inputManager.CheckKeyState(SDLK_w, HOLD))
    {
        inputForce.y -= 1;
    }
    if (inputManager.CheckKeyState(SDLK_s, HOLD))
    {
        inputForce.y += 1;
    }
    if (inputManager.CheckKeyState(SDLK_a, HOLD))
    {
        inputForce.x -= 1;
    }
    if (inputManager.CheckKeyState(SDLK_d, HOLD))
    {
        inputForce.x += 1;
    }

    if (inputManager.CheckKeyState(SDLK_SPACE, PRESSED))
    {
        spawner->InsertObject(player->SpawnBullet());
    }

    inputForce.Normalize();
    inputForce = inputForce * 30;
    player->GetRigidbody()->AddForce(inputForce);

}

void MainMenu::Render()
{
	for (Object* o : objects)
	{
		o->Render(renderer);
	}

	player->Render(renderer);
}

