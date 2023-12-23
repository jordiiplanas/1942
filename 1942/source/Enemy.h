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
	float timeBetweenShoots = 5000;
	float currentTime;
	float lastShootTime;
	Transform* transformPlayer;
	virtual void UpdateMovementPattern(float dt) = 0;
public:	
	Enemy(int health, int score, Transform* transformPlayer ) : health(health), score(score), transformPlayer(transformPlayer), GameObject(Vector2(16,16)) 
	{
		lastShootTime = SDL_GetTicks();
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 203), Vector2(15, 14)));
		renderer = renderers["idle"];
		SetScale(Vector2(1, 1));
		SetPosition(Vector2(200, 10));
	}
	virtual void Update(float dt) override;
	virtual Object* Shoot(Vector2 position);
	virtual void OnCollisionEnter(Object* other) override;
};