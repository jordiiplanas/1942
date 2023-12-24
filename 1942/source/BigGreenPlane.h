#pragma once
#include "Enemy.h"

class BigGreenPlane : public Enemy
{
protected:
	bool isGoingUp;
	Vector2 targetPosition;
	bool inMovement = false;
	float currentTime, lastMovement, timeBetweenMoves;
	bool shoot = false;

public:
	BigGreenPlane(Transform* transform) : isGoingUp(true), Enemy(32, 4400, transform, Vector2(48, 48))
	{
		currentTime = 0;
		timeBetweenMoves = 2;
		rigidbody->SetLinearDrag(7);
		lastMovement = SDL_GetTicks();
		float xRandom = rand() % (450 - 50 + 1) + 50;
		SetPosition(Vector2(xRandom, 500));
	}

	void Update(float dt) override
	{
		UpdateMovementPattern(dt);
		Enemy::Update(dt);
		if (!isGoingUp)
		{
			if (inMovement)
			{				
				rigidbody->AddForce(targetPosition * 6);
			}
			else
			{
				if (!shoot && currentTime > 1)
				{
					SPAWNER.InsertObject(Shoot(transformPlayer->position));
					shoot = true;
				}
				
			}
		}
		else
			rigidbody->AddForce(Vector2(0, -10));
	}

	void UpdateMovementPattern(float dt) override
	{
		if (transform->position.y < rand() % (300 - 200 + 1) + 200)
			isGoingUp = false;

		if (!isGoingUp)
		{			
			currentTime += dt;
			if (currentTime > timeBetweenMoves)
			{
				shoot = false;
				currentTime = 0;
				inMovement = !inMovement;
				float x = rand() % (650 - (-650) + 1) + -(650);
				float y = rand() % (450 - 50 + 1) + 50;
				targetPosition = Vector2(x, -y);
				targetPosition.Normalize();
			}			
		}
	}
};