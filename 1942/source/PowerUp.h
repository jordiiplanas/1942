#pragma once
#include "GameObject.h"


class PowerUp : public GameObject
{
public:	
	PowerUp(Vector2 size) : GameObject(Vector2(size.x,size.y))
	{
		renderer = new ImageRenderer(transform, Vector2(6, 140), Vector2(13, 9));
		SetPosition(Vector2(100, 100));
		rigidbody->SetVelocity(Vector2(0, 100));
	}
	virtual void Update(float dt) override
	{
		if (transform->position.y > 520)
		{
			Destroy();
		}
		Object::Update(dt);

	}
	
};