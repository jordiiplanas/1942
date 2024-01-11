#include "Player.h"
#include "Enemy.h"


void Player::PlayDeathAnimation()
{
    if (isDying) return;
    AUDIOMANAGER.PlayClip(deathSoundID);
	renderer = renderers["death"];
	isDying = true;
}

void Player::Shoot()
{
    if (leftSupportPlane != nullptr) leftSupportPlane->Shoot();
    if (rightSupportPlane != nullptr) rightSupportPlane->Shoot();

	Bullet* bullet = new Bullet(500, Vector2(0, -1), Vector2(16, 16), Vector2(97, 101), Vector2(11,10));

    if (isShootingFourBullets) 
        bullet = new Bullet(800, Vector2(0, -1), Vector2(20, 16), Vector2(134, 99), Vector2(17, 12));

    Vector2 position = Vector2(0,-transform->size.y/2);
	bullet->SetPosition(GetCenteredPosition() + position);
    SPAWNER.InsertObject(bullet);

}

void Player::AddSupportPlane()
{
    AUDIOMANAGER.PlayClip(powerUpSoundID);
    
    if (leftSupportPlane == nullptr)
	{
        leftSupportPlane = new SupportPlane(true);
        leftSupportPlane->SetPosition(GetCenteredPosition() + Vector2(-transform->size.x, 0));
        SPAWNER.InsertObject(leftSupportPlane);
	}

	if (rightSupportPlane == nullptr)
	{
        rightSupportPlane = new SupportPlane(false);
        rightSupportPlane->SetPosition(GetCenteredPosition() + Vector2(transform->size.x, 0));
        SPAWNER.InsertObject(rightSupportPlane);
	}
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
    if (isDying)
    {
        DieTimer(deltaTime);
        if (isDying) return;
	}
    if (isRolling)
    {
        RollTimer(deltaTime);
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

	/*if (isDying)
	{
		timeToDie -= deltaTime;
		if (timeToDie <= 0)
		{
			isPendingDestroy = true;
		}
	}*/

    ApplyInput(deltaTime);

    ChangeAnimation(currentAnimation);

    GameObject::Update(deltaTime);
}
void Player::ApplyInput(float deltaTime)
{
    Vector2 inputForce = Vector2(0, 0);
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
    if (inputManager.CheckKeyState(SDLK_j, PRESSED))
    {
        AUDIOMANAGER.PlayClip(flipSoundID);
        isRolling = true;
    }
    if (inputManager.CheckKeyState(SDLK_SPACE, HOLD))
    {
        lastShootTime += deltaTime;
        if (lastShootTime > shootDelay)
        {
            lastShootTime = 0;
            AUDIOMANAGER.PlayClip(shootSoundID);
            Shoot();
        }
    }
    inputForce.Normalize();
    inputForce = inputForce * 50;
    GetRigidbody()->AddForce(inputForce);
    MoveSupportPlanes();
}

void Player::RollTimer(float deltaTime)
{
    if (isRolling)
    {
        timeRolling += deltaTime;
        if (timeRolling > timeToRoll)
        {
            isRolling = false;
            RollsUi.top()->Destroy();
            RollsUi.pop();
            timeRolling = 0;
        }
        currentAnimation = "roll";
    }
}

void Player::DieTimer(float deltaTime)
{
    timePassed += deltaTime;
    if (timePassed > timeToDie)
    {
        LifesUi.top()->Destroy();
        LifesUi.pop();
        lives--;
        isShootingFourBullets = false;
        if (leftSupportPlane != nullptr) leftSupportPlane->PlayDeathAnimation();
        if (rightSupportPlane != nullptr) rightSupportPlane->PlayDeathAnimation();
        isDying = false;
        if (lives == 0)
        {
            isPendingDestroy = true;
            isDying = false;
            return;
        }
        timePassed = 0;

        currentAnimation = "idle";
        renderer = renderers[currentAnimation];
        isRespawning = true;
        transform->position = Vector2(2000, 2000);
    }
}

void Player::OnCollisionEnter(Object* other)
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

