#pragma once
#include "Renderer.h"
#include "SDL_ttf.h"

class TextRenderer : public Renderer {
protected:
    std::string text;
    std::string fontPath;
    TTF_Font* font;
    SDL_Color color;
    int pointSize;

public:
    virtual void Update(float dt) override {}

    void SetText(std::string text, int pointSize, SDL_Color color) {
        if (texture != nullptr)
        {
            SDL_DestroyTexture(texture);
        }

        font = TTF_OpenFont(fontPath.c_str(), pointSize);
        assert(font);

        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
        assert(surface);

        //Create texture
        texture = SDL_CreateTextureFromSurface(RENDERMANAGER.GetRenderer(), surface);
        assert(texture);

        surfaceWeight = surface->w;
        surfaceHeight = surface->h;

        TTF_CloseFont(font);
        SDL_FreeSurface(surface);

        sourceRect = { 0, 0, surfaceWeight, surfaceHeight };
        destRect = {
        (int)transform->position.x,
        (int)transform->position.y,
        (int)text.length() * pointSize,
        pointSize * 2

        };

        this->text = text;
        this->color = color;
        this->pointSize = pointSize;
    }
    TextRenderer(std::string text, int pointSize, SDL_Color color, Transform* t, std::string resourcePath)
        : Renderer(t), text(text), pointSize(pointSize), color(color) {

        fontPath = resourcePath;
        SetText(text, pointSize, color);
    }

    ~TextRenderer() {
        SDL_DestroyTexture(texture);
    }
};