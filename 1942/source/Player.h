#pragma once
#include "GameObject.h"
#include "EnemyBullets.h"
#include "AnimatedImageRenderer.h"
#include "InputManager.h"
#include "SupportPlane.h"


class Player : public GameObject
{
private:
	bool isRolling = false;
	float fireTime = 0.2f;
	float lastFireTime;
	bool doubleFire;
	float timeToDie = 3;
	bool isDying = false;

	float shootDelay = 0.1f;
	float lastShootTime = 0;

	std::vector<SupportPlane*> supportPlanes;

public:
	Player(Vector2 position) : GameObject(Vector2(32, 32)) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(0,0), Vector2(32, 32)));
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
		renderers.emplace("death", new AnimatedImageRenderer(transform, Vector2(0,112), Vector2(32, 32), deathDeltas, false, 20));
		renderer = renderers["idle"];
		rigidbody->SetLinearDrag(10);
		SetScale(Vector2(1.5f, 1.5f));
		SetPosition(position);
	}

	void OnCollisionEnter(Object* other) override;
	bool IsDying() { return isDying; }
	void PlayDeathAnimation();
	void Shoot();
	void AddSupportPlane(bool isLeft);
	void MoveSupportPlanes();
	void Update(float deltaTime) override;
};