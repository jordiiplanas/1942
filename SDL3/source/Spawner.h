#pragma once

#include <queue>
#include "Object.h"

class Spawner
{
private:
	std::queue<Object*> objectsToSpawn;
	bool canSpawn = false;
public:
	Spawner() = default;
	void InsertObject(Object* object);
	bool CanSpawn() { return canSpawn; }
	Object* SpawnObject();

};