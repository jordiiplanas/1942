#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{
    Object* playButton = new Button(Vector2(155, 50), "Gameplay", "Play");
    Object* rankButton = new Button(Vector2(155, 150), "Ranking", "Ranking");
    Object* exitButton = new Button(Vector2(155, 250), "Gameplay", "Exit");
    Object* muteButton = new Button(Vector2(155, 350), "Gameplay", "Mute");
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
    }

}

void MainMenu::Render()
{
    for (Object* o : ui)
    {
        o->Render();
    }
}

