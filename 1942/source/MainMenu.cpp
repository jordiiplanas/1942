#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{
   /* player = new Player(
        "resources/1942.png",
        Vector2(100, 64),
        Vector2(5, 6),
        Vector2(26, 16),
        renderer);
    
        
    player->GetRigidbody()->SetLinearDrag(5);
    player->SetPosition(Vector2(256, 256));    

    sfxID = AUDIOMANAGER.LoadClip("resources/audios/rave.wav");
    AUDIOMANAGER.PlayClip(sfxID);*/
}

MainMenu::~MainMenu()
{

}

void MainMenu::OnEnter()
{
    nextScene = "Gameplay";
}


void MainMenu::Update(float dt)
{
    

}

void MainMenu::Render()
{
	/*for (Object* o : objects)
	{
		o->Render(renderer);
	}

	player->Render(renderer);*/
}

