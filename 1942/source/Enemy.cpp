#include "Enemy.h"



void Enemy::Update(float dt)
{
	Object::Update(dt);
	spawner->InsertObject(Shoot(Vector2()));
	if (health <= 0)
		Destroy();
}

Object* Enemy::Shoot(Vector2 position)
{
	EnemyBullet* bullet = new EnemyBullet(500, Vector2(16, 16), playerPosition);

	bullet->SetPosition(GetCenteredPosition() + position);
	return bullet;
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


