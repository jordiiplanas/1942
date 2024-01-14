#include "Enemy.h"



void EnemyPlane::Update(float dt)
{
	currentTime = SDL_GetTicks();
	
	if (health <= 0)
	{
		SCOREMANAGER.AddScore(score);
		Destroy();
		return;
	}
	if (transform->position.x > RENDERMANAGER.GetWindowSize().x + transform->size.x
		|| transform->position.x < -transform->size.x
		|| transform->position.y > RENDERMANAGER.GetWindowSize().y + transform->size.y
		|| transform->position.y < -transform->size.y)
	{
		Destroy();
		return;
	}

	
	GameObject::Update(dt);

	
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


