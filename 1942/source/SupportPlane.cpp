#include "SupportPlane.h"



void SupportPlane::Shoot()
{
	Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(3.2, 16), Vector2(86, 101), Vector2(2, 10));

	Vector2 position = Vector2(-transform->size.x/8,-transform->size.y);
	bullet->SetPosition(GetCenteredPosition() + position);
	SPAWNER.InsertObject(bullet);
}

void SupportPlane::PlayDeathAnimation()
{
	if (isDying) return;
	renderer = renderers["death"];
	isDying = true;
}

void SupportPlane::Update(float deltaTime)
{
	rigidbody->Update(deltaTime);
	renderer->Update(deltaTime);
	if (isDying)
	{
		timePassed += deltaTime;
		if (timePassed >= timeToDie)
		{
			std::cout << "que me muelo\n";
			Destroy();
		}
	}
}

void SupportPlane::OnCollisionEnter(Object* other)
{
	if (isRolling || isDying) return;

	if (dynamic_cast<Enemy*>(other))
	{
		PlayDeathAnimation();
	}
	else
	if (dynamic_cast<EnemyBullet*>(other))
	{
		PlayDeathAnimation();
		other->Destroy();
	}
}
