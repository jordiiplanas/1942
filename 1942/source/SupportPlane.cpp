#include "SupportPlane.h"



void SupportPlane::Shoot()
{
	Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(3.2, 16), Vector2(86, 101), Vector2(2, 10));

	Vector2 position = Vector2(-transform->size.x/8,-transform->size.y);
	bullet->SetPosition(GetCenteredPosition() + position);
	SPAWNER.InsertObject(bullet);
}
