#include "Enemy.h"

Enemy::Enemy(int health, int score, std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize)
	: Object(path, size, sourceOffset, sourceSize), health(health), score(score) {}

void Enemy::Update(float dt)
{
	Object::Update(dt);
	if (health <= 0)
		Destroy();
}

void Enemy::OnCollisionEnter(Object* other)
{
	std::cout << "Position:" << transform->position.x << " " << transform->position.y 
		<< "Size: " << transform->size.x << " " << transform->size.y << std::endl;

	

	if (dynamic_cast<Bullet*>(other))
	{
		health--;
		other->Destroy();
	}
}


