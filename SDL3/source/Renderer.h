#pragma once
#include <cassert>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <string>

#include "Transform.h"
#include "Vector2.h"

class Renderer
{
protected:
	Transform* transform;
	SDL_Texture* texture;
	int surfaceWeight;
	int surfaceHeight;


	SDL_RendererFlip flipMode;

	SDL_Rect sourceRect;
	SDL_Rect destRect;

	virtual void Load(std::string resourcePath, SDL_Renderer* renderer) = 0;
	
public:
	Renderer(Transform* transform, std::string resourcePath,
		SDL_Renderer* renderer)
	{
		this->transform = transform;
	}

	virtual void Render(SDL_Renderer* renderer);


	~Renderer()
	{
		SDL_DestroyTexture(texture);
	}

	void SetPosition(Vector2 position, bool centered = true);


};
