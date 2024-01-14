#include "Renderer.h"

void Renderer::SetPosition(Vector2 position, bool centered)
{
    destRect.x = position.x;
    destRect.y = position.y;

    if (centered)
    {
        destRect.x -= destRect.w / 2;
        destRect.y -= destRect.h / 2;
    }
  }

void Renderer::Render()
{
	SDL_Rect scaledDestRect = destRect;

	scaledDestRect.x = transform->position.x;
	scaledDestRect.y = transform->position.y;

	scaledDestRect.w *= transform->scale.x;
	scaledDestRect.h *= transform->scale.y;

	if (transform->centered)
	{
		scaledDestRect.x -= scaledDestRect.w / 2;
		scaledDestRect.y -= scaledDestRect.h / 2;
	}

	SDL_RenderCopyEx(
		RENDERMANAGER.GetRenderer(),
		texture,
		&sourceRect,
		&scaledDestRect,
		transform->angle,
		NULL,
		flipMode
	);
}