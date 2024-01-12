#pragma once
#include "GameObject.h"



class Button : public GameObject
{
protected: 
public:

	bool mouseIn;
	bool pressed;
	std::string nextScene;

	Button(Vector2 position, std::string scene) : mouseIn(false), pressed(false),nextScene(scene), GameObject(Vector2(128, 32))
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(6, 667), Vector2(61, 12)));
		renderers.emplace("activate", new ImageRenderer(transform, Vector2(72, 667), Vector2(61, 12)));
		renderer = renderers["idle"];
		SetPosition(position);
		SetScale(Vector2(1.6, 1.6));
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
			SCENEMANAGER.SetCurrentScene(nextScene);
			SCENEMANAGER.GetCurrentScene()->OnEnter();
		}


		
	}

};
