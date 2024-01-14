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
#include "GameplayScene.h"
#include "RankingMenu.h"
#include "EntryScene.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	RENDERMANAGER.Init();

	SCENEMANAGER.AddScene("MainMenu", new MainMenu());
	SCENEMANAGER.AddScene("Gameplay", new GameplayScene());
	SCENEMANAGER.AddScene("Ranking", new RankingMenu());
	SCENEMANAGER.AddScene("EntryScene", new EntryScene());
	SCENEMANAGER.SetCurrentScene("EntryScene");
	SCENEMANAGER.GetCurrentScene()->OnEnter();

	
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
		
			//Change of scene
			if (SCENEMANAGER.GetCurrentScene()->IsFinished())
			{
				SCENEMANAGER.SetCurrentScene(SCENEMANAGER.GetCurrentScene()->OnExit());
				SCENEMANAGER.GetCurrentScene()->OnEnter();
			}
		}
		//std::cout << inputManager.GetMouseX() << " " << inputManager.GetMouseY() << std::endl;

	}
	return 0;
}

