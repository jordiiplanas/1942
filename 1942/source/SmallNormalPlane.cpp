#include "SmallNormalPlane.h"

SmallNormalPlane::SmallNormalPlane(MovementType mT, Transform* transformPlayer, bool isRight) :
	movementType(mT), isRight(isRight), EnemyPlane(1, 50, transformPlayer, Vector2(16, 16))
{
	SetRotation(180);
	curveMovementLimit = rand() % (400 - 200 + 1) + 200;
	GetRigidbody()->SetLinearDrag(2);
	renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 203), Vector2(15, 14)));
	std::vector<Vector2> deathDeltas
	{
		Vector2(160,96), Vector2(176,96), Vector2(192,96), Vector2(208,96), Vector2(224,96), Vector2(240,96)
	};
	renderers.emplace("death", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(16, 16), deathDeltas, false, 1));
	renderer = renderers["idle"];
}

void SmallNormalPlane::Update(float dt)
{
	UpdateMovementPattern(dt);

	if (currentTime - lastShootTime > timeBetweenShoots)
	{
		SPAWNER.InsertObject(Shoot(transformPlayer->position));
		lastShootTime = SDL_GetTicks();
	}

	if (movementType == CURVE)
	{
		if (!changeMovement)
			GetRigidbody()->AddForce(Vector2(0, 8));
		else
		{
			if (isRight)
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
	EnemyPlane::Update(dt);
	if (isPendingDestroy && !isDying)
	{
		//AUDIOMANAGER.PlayClip(deathSoundIndex+ 3);
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

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	if (!changeMovement)
	{
		if (movementType == V)
		{
			if (transform->position.y > curveMovementLimit)
				changeMovement = true;
		}		
		else
		{
			if (transform->position.y > curveMovementLimit)
				changeMovement = true;
		}
	}
}


