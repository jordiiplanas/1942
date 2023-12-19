#include "Enemy.h"

<<<<<<< HEAD:SDL3/source/Enemy.cpp
Enemy::Enemy(int health, int score, std::string path, Vector2 size, Vector2 sourceOffset, Vector2 sourceSize, SDL_Renderer* sdlRenderer)
	: Object(path, size, sourceOffset, sourceSize, sdlRenderer), health(health), score(score) {}
=======
Enemy::Enemy(Vector2 position)
	: GameObject(Vector2(100, 64)) 
{
	renderers.emplace("idle", new ImageRenderer(transform, Vector2(5, 200), Vector2(15, 14)));
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
>>>>>>> main:1942/source/Enemy.cpp


