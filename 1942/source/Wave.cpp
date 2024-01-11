#include "Wave.h"

Wave::Wave(WaveType type, float startTime, int numEnemies, Transform* transform)
{
	this->type = type;
	this->startTime = startTime;
	this->numEnemies = numEnemies;
	this->playerTransform = transform;
}

void Wave::Update(float deltaTime)
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
		SpawnEnemy();
	}
}
void Wave::SpawnEnemy()
{
	EnemyPlane* enemy;
	Vector2 curvePlaner = Vector2(rand() % (350 - 100 + 1) + 50, -20);
	switch (type)
	{
	case WaveType::NORMAL:
		enemy = new SmallNormalPlane(STRAIGHT, playerTransform, true);
		enemy->SetPosition(Vector2(rand() % (450 - 50 + 1) + 50, -20));
		break;
	case WaveType::SMALLRED:
		if (initialPosition.x > 256 && initialPosition.y > 256)
			enemy = new SmallRedPlane(playerTransform, false, true);
		else if (initialPosition.x > 256 && initialPosition.y < 256)
			enemy = new SmallRedPlane(playerTransform, false, false);

		else if (initialPosition.x < 256 && initialPosition.y < 256)
			enemy = new SmallRedPlane(playerTransform, true, false);
		else
			enemy = new SmallRedPlane(playerTransform, true, true);

		enemy->SetPosition(initialPosition);
		break;
	case WaveType::MEDIUMYELLOW:
		if (!mediumSpawned)
		{
			enemy = new MediumYellowPlane(playerTransform, true, 300);
			enemy->SetPosition(Vector2(150, -20));
			mediumSpawned = true;
		}
		else
		{
			enemy = new MediumYellowPlane(playerTransform, false, 300);
			enemy->SetPosition(Vector2(350, -20));
			mediumSpawned = true;
		}
		break;
	case WaveType::BIGGREEN:
		enemy = new BigGreenPlane(playerTransform);
		break;
	case WaveType::NORMAL_V:
		enemy = new SmallNormalPlane(V, playerTransform, true);
		enemy->SetPosition(initialPosition);
		break;
	case WaveType::NORMAL_CURVE:
		if(curvePlaner.x > 256)	
		enemy = new SmallNormalPlane(CURVE, playerTransform, false);
		else
		enemy = new SmallNormalPlane(CURVE, playerTransform, true);

		enemy->SetPosition(curvePlaner);
		break;
	default:
		enemy = new SmallNormalPlane(CURVE, playerTransform, true);
		break;
	}
	//spawnedPlanes.push_back(enemy);
	SPAWNER.InsertObject(enemy);
}

void Wave::Reset()
{
	spawnedPlanes.clear();
	spawnedEnemies = 0;
	timePassed = 0;
	isFinished = false;
}
