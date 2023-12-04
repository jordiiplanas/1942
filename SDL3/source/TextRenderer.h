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

	SDL_Renderer* renderer;
	
	void Load(std::string resourcePath, SDL_Renderer* renderer) override;

public:
	void SetText(std::string text, int pointSize, SDL_Color color);

	TextRenderer(
		std::string text, 
		int pointSize, 
		SDL_Color color,
		Transform* transform, 
		std::string resourcePath,
		Vector2 sourceOffset, 
		Vector2 sourceSize,
		SDL_Renderer* renderer
	)
		: Renderer(transform, resourcePath, renderer), 
			text(text), 
			pointSize(pointSize),
			color(color),
			renderer(renderer)
	{
		Load(resourcePath, renderer);
	}

};