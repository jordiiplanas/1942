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

	bool isLeft = false;
	SupportPlane(bool isLeft) : GameObject(Vector2(22, 22)), isLeft(isLeft)
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(0, 0), Vector2(32, 32)));
		std::vector<Vector2> rightDeltas
		{
			Vector2(32,0),Vector2(32 * 3,0),Vector2(32 * 5,0)
		};
		std::vector<Vector2> leftDeltas
		{
			Vector2(32 * 2,0),Vector2(32 * 4,0),Vector2(32 * 6,0)
		};
		std::vector<Vector2> deathDeltas
		{
			Vector2(0,0), Vector2(32,0), Vector2(64,0), Vector2(96,0), Vector2(128,0), Vector2(160,0)
		};
		renderers.emplace("right", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), rightDeltas, false, 20));
		renderers.emplace("left", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), leftDeltas, false, 20));
		renderers.emplace("death", new AnimatedImageRenderer(transform, Vector2(0, 112), Vector2(32, 32), deathDeltas, false, 20));
		renderer = renderers["idle"];
		rigidbody->SetLinearDrag(10);
	}
	void Shoot();
	void PlayDeathAnimation();
	void Update(float deltaTime) override;
	void OnCollisionEnter(Object* other) override;
};