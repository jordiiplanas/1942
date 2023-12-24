#include "Wave.h"

Wave::Wave(WaveType type, float startTime, int numEnemies)
{
	this->type = type;
	this->startTime = startTime;
	this->numEnemies = numEnemies;

}

void Wave::Update(float deltaTime, Transform* transform)
{
	if (spawnedEnemies >= numEnemies)
	{
		isFinished = true;
		return;
	}
	timePassed += deltaTime;
	std::cout << timePassed << std::endl;
	if (timePassed > startTime)
	{
		timePassed = 0;
		spawnedEnemies++;
		SpawnEnemy(transform);
	}
}
void Wave::SpawnEnemy(Transform* transform)
{
	EnemyPlane* enemy;
	switch (type)
	{
	case WaveType::A:
		enemy = new SmallNormalPlane(STRAIGHT, transform, true);
		break;
	case WaveType::B:
		enemy = new SmallRedPlane(transform, true, true);
		break;
	case WaveType::C:
		enemy = new MediumYellowPlane(transform, false, 300);
		break;
	case WaveType::D:
		enemy = new BigGreenPlane(transform);	
		break;
	case WaveType::E:
		enemy = new SmallNormalPlane(V, transform, true);
		break;
	}
	spawnedPlanes.push_back(enemy);
	SPAWNER.InsertObject(enemy);
}