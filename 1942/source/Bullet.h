#pragma once

#include "Object.h"
#include "Enemy.h"

class Bullet : public Object
{
private:
	Vector2 direction = Vector2(0.0f, -1.0f);
public:

	Bullet(float speed, Vector2 direction,
		std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize)
		: Object(path, size, sourceOffset, sourceSize), direction(direction)
	{
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