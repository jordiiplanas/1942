#pragma once
#include "GameObject.h"
#include "EnemyBullets.h"
#include "Bullet.h"
#include "AnimatedImageRenderer.h"

class Player : public GameObject
{
private:
public:
	Player(Vector2 position) : GameObject(Vector2(100, 64)) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 6), Vector2(25, 16)));
		std::vector<Vector2> rightDeltas
		{
			Vector2(32,0),Vector2(32 * 3,0),Vector2(32 * 5,0)
		};
		std::vector<Vector2> leftDeltas
		{
			Vector2(32 * 2,0),Vector2(32 * 4,0),Vector2(32 * 6,0)
		};
		renderers.emplace("right", new AnimatedImageRenderer(transform, Vector2(5, 6), Vector2(25, 16), rightDeltas, false, 20));
		renderers.emplace("left", new AnimatedImageRenderer(transform, Vector2(5, 6), Vector2(25, 16), leftDeltas, false, 20));
		renderer = renderers["idle"];
		rigidbody->SetLinearDrag(10);
		SetScale(Vector2(0.5f, 0.5f));
		SetPosition(position);
	}
	~Player();

	void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<EnemyBullet*>(other))
		{
			other->Destroy();
		}
	}
	Object* SpawnBullet(Vector2 position);
};