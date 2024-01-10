#pragma once
#include "Enemy.h"



class MediumYellowPlane : public EnemyPlane
{
	
protected:
	bool spawnLeft;
	bool isSpinning = false;
	Vector2 direction;
	float radius = 2.5;
	float angle = 0;
	float actualSpeed;
	float startSpin;

public:
	MediumYellowPlane(Transform* transformPlayer, bool spawnLeft, float startSpin) :
		spawnLeft(spawnLeft), startSpin(startSpin), EnemyPlane(1, 100, transformPlayer, Vector2(32, 32))
	{
		transform->position = Vector2(100, 0);
		GetRigidbody()->SetLinearDrag(2);		
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(7, 507), Vector2(31, 30)));
		renderer = renderers["idle"];
		direction = Vector2(0, 4);
		rigidbody->SetAngularDrag(5.3);
	}

	void Update(float dt) override
	{
		if (currentTime - lastShootTime > timeBetweenShoots)
		{
			SPAWNER.InsertObject(Shoot(transformPlayer->position));
			lastShootTime = SDL_GetTicks();
		}
		EnemyPlane::Update(dt);
		UpdateMovementPattern(dt);
		if (isSpinning)
		{
			rigidbody->SetVelocity(Vector2(0, 0));	
			if (spawnLeft)
			{				
				SetPosition(Vector2(GetPosition().x + radius * sin(angle),
				GetPosition().y + radius * cos(angle)));
			}
			else
			{
				SetPosition(Vector2(GetPosition().x + radius * -sin(angle),
				GetPosition().y + radius * cos(angle)));
			}			
			angle += 0.03;
			rigidbody->AddTorque(10);
			rigidbody->SetAngularDrag(5.3);
		}
		else
		{
			rigidbody->SetAngularDrag(100);
			rigidbody->AddForce(direction);
			actualSpeed = rigidbody->GetVelocity().y;
		}
	}
	void UpdateMovementPattern(float dt) override
	{
		if (transform->position.y >startSpin)
		{
			isSpinning = true;
		}
		if (angle > M_PI * 2)
		{
			rigidbody->SetLinearDrag(3);
			isSpinning = false;
			rigidbody->SetVelocity(Vector2(0, actualSpeed));
		}
	}
};
