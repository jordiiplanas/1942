#include "Enemy.h"

Enemy::Enemy(int health, int score, std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize, SDL_Renderer* sdlRenderer)
	: Object(path, size, sourceOffset, sourceSize, sdlRenderer), health(health), score(score) {}


