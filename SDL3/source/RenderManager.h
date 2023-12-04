#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>

#define RENDERMANAGER RenderManager::Instance()


class RenderManager
{
private:
	
	
	
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	inline static RenderManager& Instance() 
	{
		static RenderManager renderManager;
		return renderManager;
	}
	
	RenderManager() = default;
	RenderManager(RenderManager&) = delete;
	RenderManager operator=(const RenderManager&) = delete;
	void Init();
	SDL_Renderer* GetRenderer() { return renderer; }


private:

	void InitSDL();
	void CreateWindowAndRenderer();

};



