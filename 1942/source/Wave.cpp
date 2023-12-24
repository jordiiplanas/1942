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
		std::cout << "Ronda terminada waa" << std::endl;
		return;
	}
	timePassed += deltaTime;
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
		enemy->SetPosition(initialPosition);
		break;
	case WaveType::B:
		if (initialPosition.x > 256)
			enemy = new SmallRedPlane(transform, false, true);
		else
			enemy = new SmallRedPlane(transform, true, true);
		enemy->SetPosition(initialPosition);
		break;
	case WaveType::C:
		enemy = new MediumYellowPlane(transform, false, 300);
		break;
	case WaveType::D:
		enemy = new BigGreenPlane(transform);	
		break;
	case WaveType::E:
		enemy = new SmallNormalPlane(V, transform, true);
		enemy->SetPosition(initialPosition);
		break;
	}
	spawnedPlanes.push_back(enemy);
	SPAWNER.InsertObject(enemy);
}

void Wave::Reset()
{
	spawnedPlanes.clear();
	spawnedEnemies = 0;
	timePassed = 0;
	isFinished = false;
}
