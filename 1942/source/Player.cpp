#include "Player.h"
#include "Enemy.h"


void Player::PlayDeathAnimation()
{
    if (isDying) return;
	renderer = renderers["death"];
	isDying = true;
}

void Player::Shoot()
{
    if (leftSupportPlane != nullptr) leftSupportPlane->Shoot();
    if (rightSupportPlane != nullptr) rightSupportPlane->Shoot();

	Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(16, 16), Vector2(97, 101), Vector2(11,10));

    Vector2 position = Vector2(0,-transform->size.y/2);
	bullet->SetPosition(GetCenteredPosition() + position);
    SPAWNER.InsertObject(bullet);

}

void Player::AddSupportPlane(bool isLeft)
{

    if (leftSupportPlane != nullptr && isLeft ||
    rightSupportPlane != nullptr && !isLeft) return;

	SupportPlane* supportPlane = new SupportPlane(isLeft);

    if (isLeft)
	{
		supportPlane->SetPosition(GetCenteredPosition() + Vector2(-transform->size.x, 0));
        leftSupportPlane = supportPlane;
	}
	else
	{
		supportPlane->SetPosition(GetCenteredPosition() + Vector2(transform->size.x, 0));
		rightSupportPlane = supportPlane;
	}
	SPAWNER.InsertObject(supportPlane);
}

void Player::MoveSupportPlanes()
{
    if (leftSupportPlane == nullptr && rightSupportPlane == nullptr) return;

    if (leftSupportPlane != nullptr)
    {
        leftSupportPlane->isRolling = isRolling;
        leftSupportPlane->SetPosition(GetCenteredPosition() + Vector2(-transform->size.x, 0));
        if (!leftSupportPlane->isDying) leftSupportPlane->ChangeAnimation(currentAnimation);
        
    }
    if (rightSupportPlane != nullptr)
	{
        rightSupportPlane->isRolling = isRolling;
		rightSupportPlane->SetPosition(GetCenteredPosition() + Vector2(transform->size.x, 0));
        if (!rightSupportPlane->isDying) rightSupportPlane->ChangeAnimation(currentAnimation);
		
	}
}

void Player::DisableSupportPlane(Object* other)
{
    if (leftSupportPlane == other)
	{
		leftSupportPlane = nullptr;
	}
	else if (rightSupportPlane == other)
	{
		rightSupportPlane = nullptr;
	}
}

void Player::Update(float deltaTime)
{
	if (isPendingDestroy) delete this;

    if (isDying)
    {
        timePassed += deltaTime;
        if (timePassed > timeToDie)
        {
            lives--;
            if (lives == 0)
            {
				isPendingDestroy = true;
                return;
            }
            timePassed = 0;
            if (leftSupportPlane != nullptr) leftSupportPlane->PlayDeathAnimation();
            if (rightSupportPlane != nullptr) rightSupportPlane->PlayDeathAnimation();
            isDying = false;
            currentAnimation = "idle";
            renderer = renderers[currentAnimation];
            isRespawning = true;
            transform->position = Vector2(2000, 2000);
        }
	}

    if (isRespawning)
    {
        timePassed += deltaTime;
        if (timePassed > timeToRespawn)
        {
            isRespawning = false;
            timePassed = 0;
            transform->position = initialPosition;
        }
    }

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
            currentAnimation = "left";
        }
        else if (inputManager.CheckKeyState(SDLK_d, HOLD) && GetPosition().x < 450)
        {
            inputForce.x += 1;
            currentAnimation = "right";
        }
        else 
        {
            currentAnimation = "idle";
            
        }

        if (isRolling)
        {
            timeRolling += deltaTime;
            if (timeRolling > timeToRoll)
			{
				isRolling = false;
				timeRolling = 0;
			}
            currentAnimation = "roll";
        }

        ChangeAnimation(currentAnimation);

        if (inputManager.CheckKeyState(SDLK_SPACE, HOLD))
        {
            lastShootTime += deltaTime;
            if (lastShootTime > shootDelay)
			{
				lastShootTime = 0;
                Shoot();
			}
        }

        if (inputManager.CheckKeyState(SDLK_j, PRESSED))
        {
            isRolling = true;
        }
        
    }

    if (inputManager.CheckKeyState(SDLK_e, PRESSED))
    {
        PlayDeathAnimation();
    }

    if (inputManager.CheckKeyState(SDLK_q, PRESSED))
	{
		AddSupportPlane(true);
        AddSupportPlane(false);
	}

    inputForce.Normalize();
    inputForce = inputForce * 50;
    GetRigidbody()->AddForce(inputForce);
    MoveSupportPlanes();
    
}

void Player::OnCollisionEnter(Object* other)
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

