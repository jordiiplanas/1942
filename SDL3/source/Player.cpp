#include "Player.h"

Player::Player(std::string path, Vector2 size, Vector2 sourceOffset,
	Vector2 sourceSize, SDL_Renderer* sdlRenderer)
	: Object(path, size, sourceOffset, sourceSize, sdlRenderer) {}

Bullet* Player::SpawnBullet()
{
	Bullet* bullet = new Bullet(
		200,
		Vector2(0, -1),
		"resources/1942.png",
		Vector2(5, 40),
		Vector2(92, 84),
		Vector2(1, 8),
		sdlRenderer);

	bullet->SetPosition(GetCenteredPosition() + Vector2(0, -80));
	return bullet;
}