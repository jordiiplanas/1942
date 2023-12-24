#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Spawner.h"
#include "ScoreManager.h"


class PowerUp : public GameObject
{
protected:
	Player* player;
	
	
public:	
	PowerUp(Player& p, Vector2 size) : player(&p), GameObject(Vector2(size.x,size.y))
	{
		renderer = new ImageRenderer(transform, Vector2(6, 140), Vector2(13, 9));
		SetPosition(Vector2(100, 100));
		rigidbody->SetVelocity(Vector2(0, 100));
	}
	virtual void Update(float dt) override
	{
		Object::Update(dt);
		if (transform->position.y > 520)
		{
			Destroy();
		}
	}
	void OnCollisionEnter(Object* other) override
	{	
		SCOREMANAGER.AddScore(1000);
	};
};