#pragma once
#include "GameObject.h"

class EnemyBullet : public GameObject
{
private:
	Vector2 direction;
public:
	EnemyBullet(float speed, Vector2 size, Vector2 direction)
		: GameObject(size)
	{		
		direction.Normalize();
		this->direction = direction;
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(69,107), Vector2(4,4)));
		renderer = renderers["idle"];
		rigidbody->SetVelocity(direction * speed);
	}

	virtual void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
		if (transform->position.y >= 500 ||transform->position. y <= 0 
			|| transform->position.x> 500 || transform->position.x<0)
		{
			Destroy();
		}
	}
};