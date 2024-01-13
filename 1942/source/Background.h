#pragma once
#include "GameObject.h"

class Background : public GameObject
{
public:
	Background(Vector2 size, float speed)
		: GameObject(size) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(640, 0), Vector2(192, 192)));
		renderers.emplace("initial", new ImageRenderer(transform, Vector2(640, 240), Vector2(192, 192)));
		renderers.emplace("final", new ImageRenderer(transform, Vector2(640, 416), Vector2(192, 192)));
		renderers.emplace("island1", new ImageRenderer(transform, Vector2(848,368), Vector2(192,192)));
		renderers.emplace("island2", new ImageRenderer(transform, Vector2(864,0), Vector2(192,192)));
		renderer = renderers["idle"];
		rigidbody->SetVelocity(Vector2(0,speed));
	}
	virtual void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
		if (transform->position.y >= 512)
		{
			transform->position.y = -512;
			if (renderer != renderers["idle"])
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