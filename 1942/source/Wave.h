#pragma once

#include "SmallNormalPlane.h"
#include "BigGreenPlane.h"
#include "SmallRedPlane.h"
#include "MediumYellowPlane.h"
#include "Player.h"

enum WaveType
{
	A,
	B,
	C,
	D,
	E,
	F
};

class Wave
{
private:
	float timePassed = 0;
	int spawnedEnemies = 0;

	Vector2 initialPosition;
	float startTime;
	WaveType type;
	int numEnemies;
	std::vector<EnemyPlane*> spawnedPlanes;
	bool isFinished;
	bool mediumSpawned = false;

public:
	Wave(WaveType type, float startTime, int numEnemies);

	void SetInitialPosition(Vector2 position) { initialPosition = position; }
	void Update(float deltaTime, Transform* transform);
	void Draw();
	void SpawnEnemy(Transform* transform);
	void Reset();
	bool IsFinished() { return isFinished; }
};