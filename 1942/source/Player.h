#pragma once
#include "Bullet.h"

class Player : public Object
{
private:
public:
	Player();
	Player(std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize);
	~Player();

	Object* SpawnBullet(Vector2 position);
};