#pragma once
#include "Bullet.h"
#include "RenderManager.h"

class Spawner
{
protected:
	std::vector<Object*> objectToSpawn;
public:
	Spawner();

	Object* SpawnBullet(Object* origen)
	{
		// esto tiene que estar dentro del player
		// spawner debería ser singleton

		// ya que desde el player le diremos, oye, spawnera esto
		// y el spawner lo meterá en la lista de la escena

		// importante mirar la foto que he hecho en clase

		Bullet* bullet = new Bullet(
			200,
			Vector2(0, -1),
			"resources/1942.png",
			Vector2(5, 40),
			Vector2(92, 84),
			Vector2(1, 8),
			RENDERMANAGER.GetRenderer());

		bullet->SetPosition(origen->GetCenteredPosition() + Vector2(0,-80));

		return bullet;
	}
};