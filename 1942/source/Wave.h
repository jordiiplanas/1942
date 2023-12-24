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
	E
};

class Wave
{
private:
	float timePassed = 0;
	int spawnedEnemies = 0;

	float startTime;
	WaveType type;
	int numEnemies;
	std::vector<EnemyPlane*> spawnedPlanes;
	bool isFinished;

public:
	Wave(WaveType type, float startTime, int numEnemies);

	void Update(float deltaTime, Transform* transform);
	void Draw();
	void SpawnEnemy(Transform* transform);
	bool IsFinished() { return isFinished; }
};