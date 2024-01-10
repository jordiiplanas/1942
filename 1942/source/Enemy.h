<<<<<<< HEAD:SDL3/source/Enemy.h
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
	Enemy(int health, int score,std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize, SDL_Renderer* sdlRenderer);
	~Enemy();	
=======
#pragma once
#include "GameObject.h"
#include "EnemyBullet.h"
#include "Spawner.h"
#include "Bullet.h"
#include "AudioManager.h"
#include "AnimatedImageRenderer.h"
#include "ScoreManager.h"

class EnemyPlane : public GameObject
{
protected:
	int health;
	int score;
	int movementStage = 0;
	float movementTime = 0;	
	float timeBetweenShoots = 3000;
	float currentTime;
	float lastShootTime;
	Transform* transformPlayer;
	int deathSoundIndex = 0;

	virtual void UpdateMovementPattern(float dt) = 0;
public:	
	EnemyPlane(int health, int score, Transform* transformPlayer, Vector2 size ) : health(health), score(score), transformPlayer(transformPlayer), GameObject(size) 
	{
		lastShootTime = SDL_GetTicks();
		//deathSoundIndex = AUDIOMANAGER.LoadClip("resources/audios/aaaaaa.mp3");
	}
	virtual void Update(float dt) override;
	virtual Object* Shoot(Vector2 position);
	virtual void OnCollisionEnter(Object* other) override;
>>>>>>> main:1942/source/Enemy.h
};