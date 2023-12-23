#pragma once

#include "GameObject.h"
#include "Enemy.h"

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
		Object::Update(deltaTime);
		if (transform->position.y <= -transform->size.y)
		{
			Destroy();
		}
	}	
	virtual void OnCollisionEnter(Object* other) override;
};