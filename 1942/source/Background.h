#pragma once
#include "GameObject.h"

class Background : public GameObject
{
public:
	Background(Vector2 size, float speed)
		: GameObject(size) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(608, 0), Vector2(173, 173)));
		renderers.emplace("island", new ImageRenderer(transform, Vector2(864, 0), Vector2(173, 173)));
		renderer = renderers["idle"];
		rigidbody->SetVelocity(Vector2(0,speed));
	}
	virtual void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
		if (transform->position.y >= 512)
		{
			transform->position.y = -512;
			if (renderer == renderers["island"])
			{
				renderer = renderers["idle"];
			}
			if (rand() % 4 == 1)
			{
				renderer = renderers["island"];
			}
		}
	}
};