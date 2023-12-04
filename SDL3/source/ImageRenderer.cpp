#include "ImageRenderer.h"

void ImageRenderer::Load(std::string resourcePath, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(resourcePath.c_str());
	assert(surface);

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	assert(texture);

	surfaceWeight = surface->w;
	surfaceHeight = surface->h;

	SDL_FreeSurface(surface);
}

