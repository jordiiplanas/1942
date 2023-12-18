#pragma once
#include "Bullet.h"

class Player : public Object
{
private:
public:
	Player(Vector2 position);
	~Player();

	Object* SpawnBullet(Vector2 position);
};