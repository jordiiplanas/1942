#pragma once
#include "Enemy.h"

class SmallRedPlane : public Enemy
{
protected:
	bool goesRight;
	bool isSpinning = false;
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
		GetRigidbody()->SetLinearDrag(2);
	}

	void Update(float dt) override 
	{
		Enemy::Update(dt);
		GetRigidbody()->AddForce(CalculateTangentialVector(10,2,dt));
		GetRigidbody()->AddForce(Vector2(0,10));
	}
	void UpdateMovementPattern(float dt) override {}
};