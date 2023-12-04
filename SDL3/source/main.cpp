#include <iostream>
#include <SDL.h>

#include "RenderManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

#include "Object.h"
#include "Renderer.h"
#include "Vector2.h"
#include "AABB.h"
#include "MainMenu.h"


int main(int argc, char* argv[])
{
	RENDERMANAGER.Init();

	SCENEMANAGER.AddScene("Main Menu", new MainMenu());
	SCENEMANAGER.SetCurrentScene("Main Menu");

	
	while (!inputManager.GetQuitEvent())
	{
		TIME.Update();

		if (TIME.ShouldUpdateGame())
		{
			inputManager.Listen();

			//Update
			SCENEMANAGER.GetCurrentScene()->Update(TIME.GetDeltaTime());

			//Render
			SDL_RenderClear(RENDERMANAGER.GetRenderer());

			SCENEMANAGER.GetCurrentScene()->Render();

			SDL_RenderPresent(RENDERMANAGER.GetRenderer());

			//Time control
			TIME.ResetDeltaTime();
		}
		//std::cout << inputManager.GetMouseX() << " " << inputManager.GetMouseY() << std::endl;

	}
	return 0;
}

