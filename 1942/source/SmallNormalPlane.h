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
	void UpdateMovementPattern(float dt) override {}
public:
	SmallNormalPlane(MovementType mT, Spawner* spawner, Transform* transformPlayer) : movementType(mT), Enemy(1, 50, spawner, transformPlayer)
	{

	}
	void Update(float dt) override
	{
		Enemy::Update(dt);
	}
};
