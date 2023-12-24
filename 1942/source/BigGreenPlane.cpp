#include "BigGreenPlane.h"

BigGreenPlane::BigGreenPlane(Transform* playerTransform) : isGoingUp(true), EnemyPlane(32, 4400, playerTransform, Vector2(64, 64))
{
	float xRandom = rand() % (450 - 50 + 1) + 50;
	transform->position = Vector2(xRandom, 500);
	currentTime = 0;
	timeBetweenMoves = 2;
	renderers.emplace("idle", new ImageRenderer(transform, Vector2(7, 364), Vector2(63, 48)));
	renderer = renderers["idle"];
	rigidbody->SetLinearDrag(7);
	lastMovement = SDL_GetTicks();
}

void BigGreenPlane::Update(float dt)
{
	UpdateMovementPattern(dt);
	EnemyPlane::Update(dt);
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

void BigGreenPlane::UpdateMovementPattern(float dt)
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
