#include "Enemy.h"

Enemy::Enemy(int health, int score, std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize)
	: Object(path, size, sourceOffset, sourceSize), health(health), score(score) {}


