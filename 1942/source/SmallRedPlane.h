#pragma once
#include "Enemy.h"

class SmallRedPlane : public Enemy
{
protected:
	bool goesRight;
	bool isSpinning = false;
public:
	SmallRedPlane(Transform* transformPlayer, bool goesRight) :
	 goesRight(goesRight), Enemy(1, 100, transformPlayer) {}

	void Update(float dt) override {}
	void UpdateMovementPattern(float dt) override {}
};