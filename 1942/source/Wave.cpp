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
	Vector2 curvePlaner = Vector2(rand() % (350 - 100 + 1) + 50, -20);
	switch (type)
	{
	case WaveType::A:
		enemy = new SmallNormalPlane(STRAIGHT, transform, true);
		enemy->SetPosition(Vector2(rand() % (450 - 50 + 1) + 50, -20));
		break;
	case WaveType::B:
		if (initialPosition.x > 256 && initialPosition.y > 256)
			enemy = new SmallRedPlane(transform, false, true);
		else if (initialPosition.x > 256 && initialPosition.y < 256)
			enemy = new SmallRedPlane(transform, false, false);

		else if (initialPosition.x < 256 && initialPosition.y < 256)
			enemy = new SmallRedPlane(transform, true, false);
		else
			enemy = new SmallRedPlane(transform, true, true);

		enemy->SetPosition(initialPosition);
		break;
	case WaveType::C:
		if (!mediumSpawned)
		{
			enemy = new MediumYellowPlane(transform, true, 300);
			enemy->SetPosition(Vector2(150, -20));
			mediumSpawned = true;
		}
		else
		{
			enemy = new MediumYellowPlane(transform, false, 300);
			enemy->SetPosition(Vector2(350, -20));
			mediumSpawned = true;
		}
		break;
	case WaveType::D:
		enemy = new BigGreenPlane(transform);	
		break;
	case WaveType::E:
		enemy = new SmallNormalPlane(V, transform, true);
		enemy->SetPosition(initialPosition);
		break;
	case WaveType::F:
		if(curvePlaner.x > 256)	
		enemy = new SmallNormalPlane(CURVE, transform, false);
		else
		enemy = new SmallNormalPlane(CURVE, transform, true);

		enemy->SetPosition(curvePlaner);
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
