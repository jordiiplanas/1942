#pragma once
#include "GameObject.h"

class EnemyBullet : public GameObject
{
private:
	Vector2 direction;

public:
	EnemyBullet(float speed, Vector2 size, Vector2 direction);
	virtual void Update(float deltaTime) override;
};