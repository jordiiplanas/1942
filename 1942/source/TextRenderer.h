#pragma once

#include "Renderer.h"
#include <SDL_ttf.h>

class TextRenderer : public Renderer
{
protected:
	std::string fontPath;
	TTF_Font* font;

	std::string text;
	int pointSize;
	SDL_Color color;

public:
	void SetText(std::string text, int pointSize, SDL_Color color);
	TextRenderer(
		std::string text,
		int pointSize,
		SDL_Color color,
		Transform* transform,
		std::string resourcePath
	)
		: Renderer(transform), 
			text(text), 
			pointSize(pointSize),
			color(color)
	{
		fontPath = resourcePath;
		SetText(text, pointSize, color);
		
	}
	~TextRenderer()
	{
		SDL_DestroyTexture(texture);
	}
};