#pragma once
#include "Enemy.h"

class SmallRedPlane : public Enemy
{
protected:
	bool goesRight;
	bool isSpinning = false;
	Vector2 direction;
	Vector2 perpenDirection = Vector2();
	float lastChangeTime;
	float actualTime;

	Vector2 CalculateTangentialVector(float radius, float angularSpeed, float dt)
	{
		float x = -radius * angularSpeed * sin(angularSpeed * dt);
		float y = radius * angularSpeed * cos(angularSpeed * dt);
		return Vector2(x, y);
	}
public:
	SmallRedPlane(Transform* transformPlayer, bool goesRight) :
	 goesRight(goesRight), Enemy(1, 100, transformPlayer) 
	{ 
		lastChangeTime = SDL_GetTicks();
		transform->position = Vector2(250, 250);
		GetRigidbody()->SetLinearDrag(2);
		if (goesRight)
			direction = Vector2(5, 0);
		else
			direction = Vector2(-5, 0);
	}

	void Update(float dt) override 
	{
		actualTime = SDL_GetTicks();
		Enemy::Update(dt);		

		if (actualTime - lastChangeTime > 1000)
		{

			perpenDirection = Vector2(-direction.y, direction.x);
			lastChangeTime = SDL_GetTicks();
			direction = perpenDirection;

		}
		GetRigidbody()->AddForce(direction + perpenDirection);
		GetRigidbody()->AddTorque(4);


		/*GetRigidbody()->AddForce(CalculateTangentialVector(10,2,dt));
		GetRigidbody()->AddForce(Vector2(0,10));*/

	}
	void UpdateMovementPattern(float dt) override {}
};