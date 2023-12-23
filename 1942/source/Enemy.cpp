#include "Enemy.h"



void Enemy::Update(float dt)
{
	currentTime = SDL_GetTicks();
	Object::Update(dt);

	if (currentTime - lastShootTime > timeBetweenShoots)
	{
		SPAWNER.InsertObject(Shoot(transformPlayer->position));
		lastShootTime = SDL_GetTicks();
	}
	
	if (health <= 0)
		Destroy();
}

Object* Enemy::Shoot(Vector2 position)
{
	EnemyBullet* bullet = new EnemyBullet(500, Vector2(16, 16), Vector2(transformPlayer->position - GetCenteredPosition()));

	bullet->SetPosition(GetCenteredPosition());
	return bullet;
}

void Enemy::OnCollisionEnter(Object* other)
{

	if (dynamic_cast<Bullet*>(other))
	{
		health--;
		other->Destroy();
	}	
}


