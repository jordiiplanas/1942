#pragma once
#include "GameObject.h"
#include "AnimatedImageRenderer.h"
#include "Spawner.h"
#include "Bullet.h"
#include "Enemy.h"

class SupportPlane : public GameObject
{
protected:
	bool isArriving = false;
	float timePassed = 0;
	float timeToDie = 0.2f;
public:
	bool isDying = false;
	bool isRolling = false;
	bool isLeft = false;
	SupportPlane(bool isLeft);
	void Shoot();
	void PlayDeathAnimation();
	void Update(float deltaTime) override;
	void OnCollisionEnter(Object* other) override;
};