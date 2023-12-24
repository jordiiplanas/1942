#pragma once
#include "Enemy.h"

class SmallRedPlane : public EnemyPlane
{
protected:
	bool goesRight;
	bool isSpinning = false;
	bool spinUp;
	Vector2 direction;
	Vector2 perpenDirection = Vector2();
	float lastChangeTime;
	float actualTime;
	float radius = 2.5;
	float angle = 0;
	float actualSpeed;
	
public:
	SmallRedPlane(Transform* transformPlayer, bool goesRight, bool spinUp) :
	 goesRight(goesRight), spinUp(spinUp), EnemyPlane(1, 100, transformPlayer, Vector2(16, 16))
	{ 
		transform->angle = 90;
		lastChangeTime = SDL_GetTicks();
		transform->position = Vector2(0, 250);
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(305, 0), Vector2(15, 14)));
		renderer = renderers["idle"];
		GetRigidbody()->SetLinearDrag(2);
		if (goesRight)
			direction = Vector2(4, 0);
		else
			direction = Vector2(-4, 0);
		rigidbody->SetAngularDrag(5.3);
	}

	void Update(float dt) override 
	{

		actualTime = SDL_GetTicks();
		EnemyPlane::Update(dt);	
		UpdateMovementPattern(dt);
		if (isSpinning)
		{
			rigidbody->SetVelocity(Vector2(0, 0));
			if (goesRight && spinUp)
			{
				SetPosition(Vector2(GetPosition().x + radius * cos(angle),
					GetPosition().y + radius * -sin(angle)));
			}
			if (goesRight && !spinUp)
			{
				SetPosition(Vector2(GetPosition().x + radius * cos(angle),
					GetPosition().y + radius * sin(angle)));
			}

			if (!goesRight && !spinUp)
			{
				SetPosition(Vector2(GetPosition().x + radius * -cos(angle),
					GetPosition().y + radius * sin(angle)));
			}
			
			if (!goesRight && spinUp)
			{
				SetPosition(Vector2(GetPosition().x + radius * -cos(angle),
					GetPosition().y + radius * -sin(angle)));
			}		

			angle += 0.03;
			rigidbody->AddTorque(10);
			rigidbody->SetAngularDrag(5.3);
		}
		else
		{
			rigidbody->SetAngularDrag(100);
			rigidbody->AddForce(direction);
			actualSpeed = rigidbody->GetVelocity().x;
		}
	}
	void UpdateMovementPattern(float dt) override 
	{
		if (transform->position.x > rand() % (400 - 200 + 1) + 200)
		{
			isSpinning = true;
		}
		if (angle > M_PI * 2)
		{
			rigidbody->SetLinearDrag(3);
			isSpinning = false;
			rigidbody->SetVelocity(Vector2(actualSpeed, 0));
		}
	}
};