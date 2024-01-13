#pragma once
#include <cassert>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <string>

#include "Transform.h"
#include "Vector2.h"
#include "RenderManager.h"


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

	
public:
	SDL_Texture* GetTexture()
	{
		return texture;
	}
	Renderer(Transform* transform)
	{
		this->transform = transform;
	}

	virtual void Update(float dt) = 0;
	virtual void Render();	
	void SetPosition(Vector2 position, bool centered = true);
};
