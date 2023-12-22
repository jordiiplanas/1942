#include "Enemy.h"



void Enemy::Update(float dt)
{
	currentTime = SDL_GetTicks();
	Object::Update(dt);

	if (currentTime - lastShootTime > timeBetweenShoots)
	{
		spawner->InsertObject(Shoot(transformPlayer->position));
		lastShootTime = SDL_GetTicks();
	}
	
	if (health <= 0)
		Destroy();
}

Object* Enemy::Shoot(Vector2 position)
{
	EnemyBullet* bullet = new EnemyBullet(500, Vector2(16, 16), position);

	bullet->SetPosition(GetCenteredPosition());
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


