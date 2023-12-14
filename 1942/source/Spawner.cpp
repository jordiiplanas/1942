#include "Spawner.h"

void Spawner::InsertObject(Object* object)
{
	objectsToSpawn.push(object);
	canSpawn = true;
}

Object* Spawner::SpawnObject()
{
	if (canSpawn)
	{
		Object* object = objectsToSpawn.front();
		objectsToSpawn.pop();	
		
		if (objectsToSpawn.size() <= 0) canSpawn = false;

		return object;
	}
	return nullptr;
}