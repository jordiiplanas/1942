#include "Enemy.h"



void EnemyPlane::Update(float dt)
{
	currentTime = SDL_GetTicks();
	Object::Update(dt);	
	
	if (health <= 0)
	{
		scoreManager->AddScore(score);
		Destroy();
	}
}

Object* EnemyPlane::Shoot(Vector2 position)
{
	EnemyBullet* bullet = new EnemyBullet(500, Vector2(8, 8), Vector2(transformPlayer->position - GetCenteredPosition()));

	bullet->SetPosition(GetCenteredPosition());
	return bullet;
}

void EnemyPlane::OnCollisionEnter(Object* other)
{

	if (dynamic_cast<Bullet*>(other))
	{
		health--;
		other->Destroy();
	}	
}


