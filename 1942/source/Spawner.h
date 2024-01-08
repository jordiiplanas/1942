#pragma once

#include <queue>
#include "Object.h"

#define SPAWNER Spawner::Instance()

class Spawner
{
private:
	std::queue<Object*> objectsToSpawn;
	bool canSpawn = false;

	Spawner() : canSpawn(false) {};
	Spawner(const Spawner&) = delete;
	Spawner& operator =(const Spawner&) = delete;

public:
	inline static Spawner& Instance()
	{
		static Spawner spawner;
		return spawner;
	}
	void InsertObject(Object* object);
	bool CanSpawn() { return canSpawn; }
	Object* SpawnObject();
};