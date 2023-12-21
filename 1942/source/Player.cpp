#include "Player.h"


void Player::PlayDeathAnimation()
{
	renderer = renderers["death"];
	renderers["death"]->Reset();
	isDying = true;
}

Object* Player::SpawnBullet(Vector2 position)
{
	Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(16, 16));

	bullet->SetPosition(GetCenteredPosition() + position);
	return bullet;
}

void Player::Update(float deltaTime)
{
	if (isPendingDestroy) delete this;
	rigidbody->Update(deltaTime);
	renderer->Update(deltaTime);



	if (isDying)
	{
		timeToDie -= deltaTime;
		if (timeToDie <= 0)
		{
			isPendingDestroy = true;
		}
	}

}
