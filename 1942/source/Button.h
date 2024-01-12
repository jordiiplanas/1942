#pragma once
#include "GameObject.h"



class Button : public GameObject
{
protected: 
public:

	bool mouseIn;
	bool pressed;

	Button(Vector2 position) : mouseIn(false), pressed(false), GameObject(Vector2(128, 32))
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(6, 667), Vector2(61, 12)));
		renderers.emplace("activate", new ImageRenderer(transform, Vector2(6, 667), Vector2(61, 12));
		renderer = renderers["idle"];
		SetPosition(position);
		SetScale(Vector2(1.6, 1.6));
	}
	void Update(float dt) override
	{
		if (rigidbody->CheckOverlappingPoint(Vector2(inputManager.GetMouseX(), inputManager.GetMouseY())))
		{
			
		}
		else
		GameObject::Update(dt);
	}

};
