#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
private:
public:
	Player(Vector2 position) : GameObject(Vector2(100, 64)) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 6), Vector2(25, 16)));
		renderer = renderers["idle"];
		rigidbody->SetLinearDrag(10);
		SetScale(Vector2(0.5f, 0.5f));
		SetPosition(position);
	}
	~Player();

	Object* SpawnBullet(Vector2 position);
};