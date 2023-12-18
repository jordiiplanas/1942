#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Player.h"


class Enemy : public GameObject
{
protected:
	int health;
	int score;
	int movementStage = 0;
	float movementTime = 0;	
public:	
	Enemy(Vector2 position);
	~Enemy();
	virtual void Update(float dt) override;
	//virtual void Shoot();
	virtual void OnCollisionEnter(Object* other) override;
};