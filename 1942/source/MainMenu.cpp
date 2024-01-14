#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{
    Object* playButton = new LoadSceneButton(Vector2(155, 50), "Play", "Gameplay");
    Object* rankButton = new LoadSceneButton(Vector2(155, 150), "Ranking", "Ranking");
    Object* exitButton = new ExitButton(Vector2(155, 250), "Exit");
    Object* muteButton = new MuteButton(Vector2(155, 350), "Mute");
    ui.push_back(playButton);
    ui.push_back(rankButton);
    ui.push_back(exitButton);
    ui.push_back(muteButton);
}

MainMenu::~MainMenu()
{

}

void MainMenu::OnEnter()
{
    nextScene = "Gameplay";
    for (Object* o : ui)
	{
		if (dynamic_cast<Button*>(o))
		{
			dynamic_cast<Button*>(o)->Reset();
		}
	}
}


void MainMenu::Update(float dt)
{
    if (inputManager.CheckKeyState(SDLK_RETURN, PRESSED))
    {
        isFinished = true;
    }

    for (Object* o : ui)
    {
        o->Update(dt);
        if (dynamic_cast<Button*>(o)->IsPressed())
        {
            if (dynamic_cast<MuteButton*>(o))
            {
                dynamic_cast<MuteButton*>(o)->Mute();
            }
            if (dynamic_cast<LoadSceneButton*>(o))
            {
                isFinished = true;
                nextScene = dynamic_cast<LoadSceneButton*>(o)->GetSceneName();
            }
            if (dynamic_cast<ExitButton*>(o))
			{
                dynamic_cast<ExitButton*>(o)->Exit();
			}
        }
    }

}

void MainMenu::Render()
{
    for (Object* o : ui)
    {
        o->Render();
    }
}

