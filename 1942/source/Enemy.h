#pragma once
#include "GameObject.h"
#include "EnemyBullet.h"
#include "Spawner.h"
#include "Bullet.h"
#include "AudioManager.h"
#include "AnimatedImageRenderer.h"
#include "ScoreManager.h"
#include "SuperKiller.h"
#include <fstream>
#include <ios>

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
	inline int GetHealth() { return health; }
};