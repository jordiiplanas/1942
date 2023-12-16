#pragma once
#include "Object.h"


class Enemy : public Object
{
protected:
	int health;
	int score;
	int movementStage = 0;
	float movementTime = 0;	
public:	
	Enemy(int health, int score,std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize);
	~Enemy();
	//virtual void Update(float dt) override;
	//virtual void Shoot();
	//virtual void OnCollisionEnter(Object* other) override;
};