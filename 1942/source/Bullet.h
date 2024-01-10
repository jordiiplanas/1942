#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
private:
	Vector2 direction = Vector2(0.0f, -1.0f);
public:

	Bullet(float speed, Vector2 direction, Vector2 size, Vector2 sourceOffSet, Vector2 SourceSize)
		: GameObject(size), direction(direction)
	{
		renderers.emplace("idle", new ImageRenderer(transform,sourceOffSet, SourceSize));
		renderer = renderers["idle"];
		rigidbody->SetVelocity(direction * speed);
	}

	virtual void Update(float deltaTime) override
	{
		if (transform->position.y <= -transform->size.y)
		{
			Destroy();
			return;
		}
		GameObject::Update(deltaTime);
	}	
};