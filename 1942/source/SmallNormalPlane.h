#pragma once
#include "Enemy.h"

enum MovementType
{
	V,
	CURVE,
	STRAIGHT
};

class SmallNormalPlane : public Enemy
{
protected:
	MovementType movementType;
	float curveMovementLimit;
	bool changeMovement = false;
	bool isRight;
	void UpdateMovementPattern(float dt) override;
	
public:
	SmallNormalPlane(MovementType mT, Transform* transformPlayer, bool isRight) :
		movementType(mT), isRight(isRight), Enemy(1, 50, transformPlayer)
	{	
		curveMovementLimit = rand() % (400 - 200 + 1) + 200;		
		GetRigidbody()->SetLinearDrag(2);		
	}
	void Update(float dt) override
	{
		UpdateMovementPattern(dt);
		if (movementType == CURVE)
		{
			if(!changeMovement)
				GetRigidbody()->AddForce(Vector2(0, 8));
			else
			{
				if(isRight)
					GetRigidbody()->AddForce(Vector2(8, 0));
				else
					GetRigidbody()->AddForce(Vector2(-8, 0));
			}				
		}
		else if (movementType == V)
		{
			if (!changeMovement)
			{
				if (isRight)
					GetRigidbody()->AddForce(Vector2(2, 8));
				else
					GetRigidbody()->AddForce(Vector2(-2, 8));
			}
			else
			{
				if (isRight)
					GetRigidbody()->AddForce(Vector2(2, -8));
				else
					GetRigidbody()->AddForce(Vector2(-2, -8));
			}
		}
		else
		{
			GetRigidbody()->AddForce(Vector2(0, 8));
		}
		Enemy::Update(dt);
	}
};
