#include "TextRenderer.h"

void TextRenderer::SetText(std::string text, int pointSize, SDL_Color color)
{
	if (texture)
		SDL_DestroyTexture(texture);

	font = TTF_OpenFont(fontPath.c_str(), pointSize);
	assert(font);

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	assert(surface);

	texture = SDL_CreateTextureFromSurface(RENDERMANAGER.GetRenderer(), surface);
	assert(surface);

	surfaceWeight = surface->w;
	surfaceHeight = surface->h;

	SDL_FreeSurface(surface);
	TTF_CloseFont(font);

	sourceRect = {
		0,0,
		surfaceWeight, surfaceHeight
	};

	destRect = {
		(int)transform->position.x,
		(int)transform->position.y,
		(int)text.length() * pointSize,
		(int)pointSize
	};

	this->text = text;
	this->color = color;
	this->pointSize = pointSize;

}


