#include "SupportPlane.h"



SupportPlane::SupportPlane(bool isLeft) : GameObject(Vector2(22, 22)), isLeft(isLeft)
{
	renderers.emplace("idle", new ImageRenderer(transform, Vector2(0, 0), Vector2(32, 32)));
	std::vector<Vector2> rightDeltas
	{
		Vector2(32,0),Vector2(32 * 3,0),Vector2(32 * 5,0)
	};
	std::vector<Vector2> leftDeltas
	{
		Vector2(32 * 2,0),Vector2(32 * 4,0),Vector2(32 * 6,0)
	};
	std::vector<Vector2> deathDeltas
	{
		Vector2(0,0), Vector2(32,0), Vector2(64,0), Vector2(96,0), Vector2(128,0), Vector2(160,0)
	};
	std::vector<Vector2> rollDeltas
	{
		Vector2(0,32), Vector2(32,32), Vector2(64,32), Vector2(96,32), Vector2(128,32), Vector2(160,32), Vector2(192,32), Vector2(224,32)
		, Vector2(0,64), Vector2(32,64)
	};
	renderers.emplace("right", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), rightDeltas, false, 20));
	renderers.emplace("left", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), leftDeltas, false, 20));
	renderers.emplace("death", new AnimatedImageRenderer(transform, Vector2(0, 112), Vector2(32, 32), deathDeltas, false, 20));
	renderers.emplace("roll", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), rollDeltas, false, 20));
	renderer = renderers["idle"];
	rigidbody->SetLinearDrag(10);
}

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

	if (dynamic_cast<EnemyPlane*>(other))
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
