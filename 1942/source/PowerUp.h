#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Spawner.h"


class PowerUp : public GameObject
{
protected:
	Player* player;
	//Spawner* spawner;
	//ScoreManager
	
public:	
	PowerUp(Player& p, Vector2 size) : player(&p), GameObject(Vector2(size.x,size.y))
	{
		renderer = new ImageRenderer(transform, Vector2(6, 140), Vector2(13, 9));
		SetPosition(Vector2(100, 100));
		rigidbody->SetVelocity(Vector2(0, 100));
	}
};