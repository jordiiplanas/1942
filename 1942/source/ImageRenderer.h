#pragma once
#include "Renderer.h"

class ImageRenderer : public Renderer
{

public:
	virtual void Update(float dt) override {}

	virtual void Reset() {};
	ImageRenderer(Transform* transform, Vector2 sourceOffset, Vector2 sourceSize) 
		: Renderer(transform) 
	{
		texture = RENDERMANAGER.GetGameTexture();

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
	}	

};