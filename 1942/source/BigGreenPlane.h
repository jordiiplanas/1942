#pragma once
#include "Enemy.h"

class BigGreenPlane : public EnemyPlane
{
protected:
	bool isGoingUp;
	Vector2 targetPosition;
	bool inMovement = false;
	float currentTime, lastMovement, timeBetweenMoves;
	bool shoot = false;

public:
	BigGreenPlane(Transform* playerTransform);
	void Update(float dt) override;
	void UpdateMovementPattern(float dt) override;
};