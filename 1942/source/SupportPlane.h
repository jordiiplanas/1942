#pragma once
#include "Player.h"
#include "GameObject.h"
class SupportPlane : public GameObject
{
protected:
	//Player* player;
	bool isArriving = false;
public:
	SupportPlane(bool isLeft) : GameObject(Vector2(50, 32))
	{
		renderer = new ImageRenderer(transform, Vector2(9, 84), Vector2(15, 9));
	}
	Object* SpawnBullet(Vector2 position)
	{	
		{
			Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(16, 16), Vector2(92,84), Vector2(1, 9));
			bullet->SetPosition(GetCenteredPosition() + position);
			return bullet;
		}
	}
};