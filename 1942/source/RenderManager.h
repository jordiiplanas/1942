#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include "Vector2.h"

#define RENDERMANAGER RenderManager::Instance()


class RenderManager
{
private:
	
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* gameTexture;
	SDL_Texture* presentationTexture;

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
	inline SDL_Texture* GetGameTexture() { return gameTexture; }
	inline SDL_Texture* GetPresentationTexture() { return presentationTexture; }
	Vector2 GetWindowSize();

private:

	void InitSDL();
	void CreateWindowAndRenderer();
	void LoadGameTexture();
};



