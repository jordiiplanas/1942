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

    Vector2 inputForce = Vector2(0, 0);

    if (!IsDying())
    {

        if (inputManager.CheckKeyState(SDLK_w, HOLD) && GetPosition().y > 15)
        {
            inputForce.y -= 1;
        }
        else if (inputManager.CheckKeyState(SDLK_s, HOLD) && GetPosition().y < 470)
        {
            inputForce.y += 1;
        }
        if (inputManager.CheckKeyState(SDLK_a, HOLD) && GetPosition().x > 15)
        {
            inputForce.x -= 1;
            ChangeAnimation("left");
        }
        else if (inputManager.CheckKeyState(SDLK_d, HOLD) && GetPosition().x < 450)
        {
            inputForce.x += 1;
            ChangeAnimation("right");
        }
        else
            ChangeAnimation("idle");

        if (inputManager.CheckKeyState(SDLK_SPACE, PRESSED))
        {
            SPAWNER.InsertObject(SpawnBullet(Vector2(-32, -30)));
        }
        else if (inputManager.CheckKeyState(SDLK_SPACE, HOLD))
        {
            lastShootTime += deltaTime;
            if (lastShootTime > shootDelay)
			{
				lastShootTime = 0;
				SPAWNER.InsertObject(SpawnBullet(Vector2(-32, -30)));
			}
        }
        
    }

    if (inputManager.CheckKeyState(SDLK_e, PRESSED))
    {
        PlayDeathAnimation();
    }

    inputForce.Normalize();
    inputForce = inputForce * 50;
    GetRigidbody()->AddForce(inputForce);
}
