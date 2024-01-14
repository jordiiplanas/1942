#pragma once
#include "GameObject.h"
#include "UiText.h"



class Button : public GameObject
{
protected: 
	UiText* text;
	bool mouseIn;
	bool pressed = false;
	bool hasBeenPressed = false;

public:

	Button(Vector2 position, std::string text) 
		: mouseIn(false), pressed(false), GameObject(Vector2(128, 32))
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(6, 667), Vector2(61, 12)));
		renderers.emplace("activate", new ImageRenderer(transform, Vector2(72, 667), Vector2(61, 12)));
		renderer = renderers["idle"];
		SetPosition(position);
		this->text = new UiText(text, GetCenteredPosition() + Vector2(40,10));
		this->text->textRend->SetText(text, 20, { 255,255,255 });
		SetScale(Vector2(1.6, 1.6));
	}
	void Render() override
	{
		GameObject::Render();
		text->Render();
	}
	void ChangeTextPosition(Vector2 position)
	{
		text->SetPosition(position);
	}
	void Reset()
	{
		pressed = false;
		hasBeenPressed = false;
	}
	virtual void Update(float dt) override
	{
		GameObject::Update(dt);

		if (rigidbody->CheckOverlappingPoint(Vector2(inputManager.GetMouseX(), inputManager.GetMouseY())))
		{
			mouseIn = true;
			renderer = renderers["activate"];
		}
		else
		{
			mouseIn = false;
			renderer = renderers["idle"];
		}
		if (hasBeenPressed)
		{
			pressed = false;
		}
		if (!inputManager.mousePressed)
		{
			hasBeenPressed = false;
		}
		text->Update(dt);

		if (mouseIn && inputManager.mousePressed && !hasBeenPressed)
		{
			pressed = true;
		}
	}
	virtual bool IsPressed()
	{
		if (hasBeenPressed) return false;
		if (pressed)
		{
			hasBeenPressed = true;
			std::cout << "Button pressed" << std::endl;
		}
		return pressed;
	}
};
