#include "Player.h"

Player::Player(std::string path, Vector2 size, Vector2 sourceOffset,
	Vector2 sourceSize)
	: Object(path, size, sourceOffset, sourceSize) {}

Object* Player::SpawnBullet(Vector2 position)
{
	Bullet* bullet = new Bullet(
		500,	
		Vector2(0, -1),
		"resources/1942.png",
		Vector2(2.5f, 20),
		Vector2(92, 84),
		Vector2(1, 8)
		);

	bullet->SetPosition(GetCenteredPosition() + position);
	return bullet;
}