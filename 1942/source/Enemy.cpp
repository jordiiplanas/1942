#include "Enemy.h"

Enemy::Enemy(int health, int score, std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize)
	: Object(path, size, sourceOffset, sourceSize), health(health), score(score) {}

void Enemy::Update(float dt)
{
	if (health <= 0)
		Destroy();
}

void Enemy::OnCollisionEnter(Object* other)
{
	if (dynamic_cast<Bullet*>(other))
	{
		health--;
	}
}


