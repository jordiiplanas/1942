#include "Player.h"

Player::Player(Vector2 position)
	: Object("resources/1942.png",
		Vector2(50, 32),
		Vector2(5, 6),
		Vector2(26, 16)) {
	SetPosition(position); rigidbody->SetLinearDrag(10);
}

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