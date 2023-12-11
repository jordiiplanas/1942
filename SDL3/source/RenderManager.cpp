#include "RenderManager.h"
#include <exception>
#include <iostream>
#include "TextRenderer.h"


void RenderManager::Init() 
{
	try 
	{
		InitSDL();
		CreateWindowAndRenderer();
	}
	catch (std::exception& exception) 
	{
		std::cout << exception.what();
		SDL_Quit();
	}
	
}

void RenderManager::InitSDL()
{
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	if (result < 0)
	{
		throw SDL_GetError();
	}
	result = TTF_Init();
	if (result < 0)
	{
		throw SDL_GetError();
	}
	
}

void RenderManager::CreateWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(
		512,
		512,
		SDL_WINDOW_SHOWN,
		&window,
		&renderer
	);

	if (result < 0)
	{
		throw SDL_GetError();
	}
	SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);

}
