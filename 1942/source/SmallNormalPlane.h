#pragma once
#include "Enemy.h"


enum MovementType
{
	V,
	CURVE,
	STRAIGHT
};

class SmallNormalPlane : public EnemyPlane
{
protected:
	float currentTime = 0;
	float timeToDie = 0.5f;
	bool isDying = false;
	MovementType movementType;
	float curveMovementLimit;
	bool changeMovement = false;
	bool isRight;
	void UpdateMovementPattern(float dt) override;
	
public:
	SmallNormalPlane(MovementType mT, Transform* transformPlayer, bool isRight);
	void Update(float dt) override;
};
