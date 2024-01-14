#pragma once
#include "GameObject.h"
#include "UiText.h"



class Button : public GameObject
{
protected: 
public:
	UiText* text;

	bool mouseIn;
	bool pressed;
	std::string nextScene;

	Button(Vector2 position, std::string scene, std::string text) : mouseIn(false), pressed(false),nextScene(scene), GameObject(Vector2(128, 32))
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
	void Update(float dt) override
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

		if (mouseIn && inputManager.mousePressed)
		{
			pressed = true;
		}
		text->Update(dt);		
	}
};
