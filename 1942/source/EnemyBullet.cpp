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
	if (transform->position.x > RENDERMANAGER.GetWindowSize().x + transform->size.x
		|| transform->position.x < -transform->size.x
		|| transform->position.y > RENDERMANAGER.GetWindowSize().y + transform->size.y
		|| transform->position.y < -transform->size.y)
	{
		Destroy();
		return;
	}
	Object::Update(deltaTime);
}
