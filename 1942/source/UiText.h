#pragma once
#include "GameObject.h"
#include "TextRenderer.h"

class UiText : public GameObject {

protected:
    std::string text;
    SDL_Color color;
    TextRenderer* textRend;

public:

    UiText(std::string text, Vector2 position) : text(text), GameObject(Vector2(64,64)) {

        transform->position = position;
        transform->angle = 0;
        transform->scale = Vector2(1.f, 1.f);
        transform->size = Vector2(60.0f, 60.0f);
        color = { 255, 255, 0 };
        textRend = new TextRenderer(text, 10, color, new Transform(position, 0, Vector2(1.0f, 1.0f), Vector2(30.0f, 30.0f), true), "resources/Monocraft.ttf");
        renderer = textRend;
    }

    void Update(float dt) {
        renderer->Update(dt);
    }

    void ChangeText(std::string text) {
        textRend->SetText(text, 10, color);
    }
};
