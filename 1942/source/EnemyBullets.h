#pragma once
#include "Player.h"
#include "GameObject.h"

class EnemyBullet : public GameObject
{
private:
	Vector2 direction;
public:
	EnemyBullet(float speed, Vector2 size, Vector2 playerPos)
		: GameObject(size)
	{		
		Vector2 a(playerPos - GetCenteredPosition());
		a.Normalize();
		direction = a;
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(75,90), Vector2(3,3)));
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
	virtual void OnCollisionEnter(Object* other) override
	{
	}
};