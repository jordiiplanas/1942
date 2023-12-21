#pragma once
#include "GameObject.h"
#include "EnemyBullets.h"
#include "Player.h"
#include "Spawner.h"


class Enemy : public GameObject
{
protected:
	int health;
	int score;
	int movementStage = 0;
	float movementTime = 0;	
	Spawner* spawner;
	Transform* transformPlayer;
public:	
	Enemy(int health, int score, Spawner* spawner, Transform* transformPlayer ) : health(health), score(score), spawner(spawner), transformPlayer(transformPlayer), GameObject(Vector2(100,64)) 
	{
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 200), Vector2(15, 14)));
		renderer = renderers["idle"];
		SetScale(Vector2(0.5f, 0.5f));
	}
	~Enemy();
	virtual void Update(float dt) override;
	virtual Object* Shoot(Vector2 position);
	virtual void OnCollisionEnter(Object* other) override;
};