#pragma once

#include "SmallNormalPlane.h"
#include "BigGreenPlane.h"
#include "SmallRedPlane.h"
#include "MediumYellowPlane.h"
#include "Player.h"

enum WaveType
{
	NORMAL,
	SMALLRED,
	MEDIUMYELLOW,
	BIGGREEN,
	NORMAL_V,
	NORMAL_CURVE
};

class Wave
{
private:
	float timePassed = 0;
	int spawnedEnemies = 0;


	std::vector<EnemyPlane*> enemyPlanes;
	EnemyPlane* enemyPlane;

	Vector2 initialPosition;
	float startTime;
	WaveType type;
	bool hasSpawnedPowerUp = false;
	
	int numEnemies;
	float timeBetweenSpawns = 0.2f;

	bool isFinished;
	Transform* playerTransform;
	bool mediumSpawned = false;

public:
	//Wave() = default;
	Wave(WaveType type, float startTime, int numEnemies, Transform* transform);

	void SetInitialPosition(Vector2 position) { initialPosition = position; }
	void Update(float deltaTime);
	void Draw();
	void SpawnEnemy();
	void Reset();
	bool IsFinished() { return isFinished; }
	float GetStartTime() { return startTime; }


};