#pragma once
#include "GameObject.h"

class Background : public GameObject
{
public:
	Background(Vector2 size, float speed)
		: GameObject(size) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(608, 0), Vector2(32, 32)));
		renderer = renderers["idle"];
		rigidbody->SetVelocity(Vector2(0,speed));
	}
	virtual void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
		if (transform->position.y > 512)
		{
			transform->position.y = -32;
		}
	}
};