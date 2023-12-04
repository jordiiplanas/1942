#pragma once
#include "Renderer.h"

class ImageRenderer : public Renderer
{
protected:
	void Load(std::string resourcePath, SDL_Renderer* renderer) override;

public:

	ImageRenderer(Transform* transform, std::string resourcePath,
		Vector2 sourceOffset, Vector2 sourceSize,
		SDL_Renderer* renderer) 
		: Renderer(transform, resourcePath, renderer) 
	{
		sourceRect = SDL_Rect
		{
			(int)sourceOffset.x,
			(int)sourceOffset.y,
			(int)sourceSize.x,
			(int)sourceSize.y
		};

		destRect = SDL_Rect
		{
			(int)transform->position.x,
			(int)transform->position.y,
			(int)transform->size.x,
			(int)transform->size.y 
		};

		// Centering
		destRect.x -= destRect.w / 2;
		destRect.y -= destRect.h / 2;

		flipMode = SDL_FLIP_NONE;

		Load(resourcePath, renderer);
	}


	
	

};