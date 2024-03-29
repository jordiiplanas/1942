#include "Wave.h"

Wave::Wave(WaveType type, float startTime, int numEnemies, Transform* transform)
{
	this->type = type;
	this->startTime = startTime;
	this->numEnemies = numEnemies;
	this->playerTransform = transform;
	RandomizeInitialPosition();
}

void Wave::Update(float deltaTime)
{
	if (isFinished) return;
	
	for (EnemyPlane* enemy : enemyPlanes)
	{
		if (enemy->GetHealth() <= 0)
		{
			enemyPlanes.erase(std::remove(enemyPlanes.begin(), enemyPlanes.end(), enemy), enemyPlanes.end());
			break;
		}
	}

	
	if (spawnedEnemies <= numEnemies)
	{
		timePassed += deltaTime;
	}
	else 
	{
		if (type == WaveType::SMALLRED)
		{
			if (enemyPlanes.size() == 1)
			{
				enemyPlane = enemyPlanes[0];
				dynamic_cast<SmallRedPlane*>(enemyPlane)->SetPowerUp();
			}
		}
	}
	
	if (timePassed > timeBetweenSpawns)
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
		enemy->SetPosition(Vector2(rand() % (450 - 50 + 1) + 50, 0));
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
	enemyPlanes.push_back(enemy);
	SPAWNER.InsertObject(enemy);
}
void Wave::Reset()
{
	enemyPlanes.clear();
	spawnedEnemies = 0;
	timePassed = 0;
	isFinished = false;
}

void Wave::RandomizeInitialPosition()
{
	switch (type)
	{
		case WaveType::NORMAL:
			initialPosition = Vector2(rand() % (450 - 50 + 1) + 50, 0);
			break;
		case WaveType::SMALLRED:
			if (rand() % 2 == 1)
			{
				initialPosition = Vector2(0, rand() % (450 - 50 + 1) + 50);
			}
			else
			{
				initialPosition = Vector2(512, rand() % (450 - 50 + 1) + 50);
			}
			break;
		case WaveType::MEDIUMYELLOW:
			initialPosition = Vector2(rand() % (450 - 50 + 1) + 50, 0);
			break;
		case WaveType::NORMAL_V:
			initialPosition = Vector2(rand() % (450 - 50 + 1) + 50, 0);
			break;
		case WaveType::NORMAL_CURVE:
			initialPosition = Vector2(rand() % (450 - 50 + 1) + 50, 0);
			break;
	}
}
