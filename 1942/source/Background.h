#pragma once
#include "GameObject.h"

class Background : public GameObject
{
public:
	bool toEnd = false;
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
		if (transform->position.y >= RENDERMANAGER.GetWindowSize().y)
		{
			transform->position.y = -RENDERMANAGER.GetWindowSize().y;
			if (renderer != renderers["idle"])
			{
				renderer = renderers["idle"];
			}
			if (rand() % 3 == 1)
			{
				if (rand() % 2 == 1)
				{
					renderer = renderers["island1"];
				}
				else
				{
					renderer = renderers["island2"];
				}
			}
			if (toEnd)
			{
				renderer = renderers["final"];
			}
		}
	}
	
};