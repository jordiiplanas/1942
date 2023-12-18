#include "GameplayScene.h"

void GameplayScene::Update(float dt)
{
	isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);

 
    for (Object* o : objects)
    {
        if (!o->IsPendingDestroy())
        {
            o->Update(dt);
            continue;
        }

        
        if (dynamic_cast<Bullet*>(o))
        {
            int a = 2;
        }
        objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
        delete o;
        
        
    }

    for (Object* o : objects)
    {
        for (Object* a : objects)
        {
            if (o == a)
				continue;
            if (o->GetRigidbody()->CheckCollision(a->GetRigidbody()))
                o->OnCollisionEnter(a);
        }
    }

    if (spawner.CanSpawn())
    {
        objects.push_back(spawner.SpawnObject());
    }

    Vector2 inputForce = Vector2();

    if (inputManager.CheckKeyState(SDLK_w, HOLD) && objects[0]->GetPosition().y > 15)
    {
        inputForce.y -= 1;
    }
    else if (inputManager.CheckKeyState(SDLK_s, HOLD) && objects[0]->GetPosition().y < 470)
    {
        inputForce.y += 1;
    }
     if (inputManager.CheckKeyState(SDLK_a, HOLD) && objects[0]->GetPosition().x > 15)
    {
        inputForce.x -= 1;
        player->ChangeAnimation("left");
    }
    else if (inputManager.CheckKeyState(SDLK_d, HOLD) && objects[0]->GetPosition().x < 450)
    {
        inputForce.x += 1;
        player->ChangeAnimation("right");
    }
    else
         player->ChangeAnimation("idle");

     if (inputManager.CheckKeyState(SDLK_SPACE, PRESSED))
    {
        spawner.InsertObject(player->SpawnBullet(Vector2(8, -40)));
        spawner.InsertObject(player->SpawnBullet(Vector2(-8, -40)));
    }
    

    isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, KeyState::PRESSED);

   /* sfxID = AUDIOMANAGER.LoadClip("resources/audios/rave.wav");
    AUDIOMANAGER.FreeClip(sfxID);*/

    inputForce.Normalize();
    inputForce = inputForce * 50;
    player->GetRigidbody()->AddForce(inputForce);
}
