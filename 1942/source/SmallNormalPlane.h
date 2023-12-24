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
	float currentTime = 0;
	float timeToDie = 0.5f;
	bool isDying = false;
	MovementType movementType;
	void UpdateMovementPattern(float dt) override {}
public:
	SmallNormalPlane(MovementType mT, Transform* transformPlayer) : movementType(mT), Enemy(1, 50, transformPlayer)
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 203), Vector2(15, 14)));
		std::vector<Vector2> deathDeltas
		{
			Vector2(160,96), Vector2(176,96), Vector2(192,96), Vector2(208,96), Vector2(224,96), Vector2(240,96)
		};
		renderers.emplace("death", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(16, 16), deathDeltas, false, 1));
		renderer = renderers["idle"];
	}
	void Update(float dt) override
	{
		Enemy::Update(dt);
		if (isPendingDestroy && !isDying)
		{
			AUDIOMANAGER.PlayClip(deathSoundIndex);
			isPendingDestroy = false;
			isDying = true;
			renderer = renderers["death"];

		}
		if (isDying)
		{
			currentTime += dt;
			if (currentTime >= timeToDie)
			{
				isPendingDestroy = true;
			}
		}
		
		
	}
};
