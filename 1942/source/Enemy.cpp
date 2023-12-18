#include "Enemy.h"

Enemy::Enemy(Vector2 position)
	: Object( "resources/1942.png",
		Vector2(50, 32),
		Vector2(5, 200),
		Vector2(15, 14)) {
	SetPosition(position); health = 2; score = 100; }

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


