#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(float speed, Vector2 size, Vector2 direction)
	: GameObject(size)
{
	direction.Normalize();
	this->direction = direction;
	renderers.emplace("idle", new ImageRenderer(transform, Vector2(69, 107), Vector2(4, 4)));
	renderer = renderers["idle"];
	rigidbody->SetVelocity(direction * speed);
}

void EnemyBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);
	if (transform->position.y >= 500 || transform->position.y <= 0
		|| transform->position.x > 500 || transform->position.x < 0)
	{
		Destroy();
	}
}
