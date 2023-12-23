#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{
   
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

}

void MainMenu::Render()
{
	
}

