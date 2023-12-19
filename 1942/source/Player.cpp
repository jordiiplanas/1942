#include "Player.h"


Object* Player::SpawnBullet(Vector2 position)
{
	Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(16, 16));

	bullet->SetPosition(GetCenteredPosition() + position);
	return bullet;
}