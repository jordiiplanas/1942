#include "Enemy.h"

Enemy::Enemy(Vector2 position)
	: GameObject(Vector2(100, 64)) 
{
	renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 6), Vector2(25, 16)));
	renderer = renderers["idle"];
	SetPosition(position); health = 2; score = 100; SetScale(Vector2(0.5f, 0.5f));
}

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


