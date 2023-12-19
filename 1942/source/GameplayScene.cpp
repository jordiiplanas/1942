#include "GameplayScene.h"

void GameplayScene::Update(float dt)
{
<<<<<<< HEAD:SDL3/source/GameplayScene.cpp
	Scene::Update(dt);
	isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);

    for (Object* o : objects)
    {

        o->Update(dt);
        if (o->IsPendingDestroy())
        {
            delete o;
            objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
        }
    } 
=======
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
>>>>>>> main:1942/source/GameplayScene.cpp

    if (spawner.CanSpawn())
    {
        objects.push_back(spawner.SpawnObject());
    }

    Vector2 inputForce = Vector2();

<<<<<<< HEAD:SDL3/source/GameplayScene.cpp
    if (inputManager.CheckKeyState(SDLK_w, HOLD))
    {
        inputForce.y -= 1;
    }
    if (inputManager.CheckKeyState(SDLK_s, HOLD))
    {
        inputForce.y += 1;
    }
    if (inputManager.CheckKeyState(SDLK_a, HOLD))
    {
        inputForce.x -= 1;
    }
    if (inputManager.CheckKeyState(SDLK_d, HOLD))
    {
        inputForce.x += 1;
    }

    if (inputManager.CheckKeyState(SDLK_SPACE, PRESSED))
    {
        spawner.InsertObject(player->SpawnBullet());
    }
=======
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
        spawner.InsertObject(player->SpawnBullet(Vector2(-30, -30)));
    }
    
>>>>>>> main:1942/source/GameplayScene.cpp

    isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, KeyState::PRESSED);

   /* sfxID = AUDIOMANAGER.LoadClip("resources/audios/rave.wav");
    AUDIOMANAGER.FreeClip(sfxID);*/

    inputForce.Normalize();
<<<<<<< HEAD:SDL3/source/GameplayScene.cpp
    inputForce = inputForce * 30;
=======
    inputForce = inputForce * 50;
>>>>>>> main:1942/source/GameplayScene.cpp
    player->GetRigidbody()->AddForce(inputForce);
}
