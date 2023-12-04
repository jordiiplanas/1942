#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{

    // Spawner -> Genera objetos

    
    

    objects.push_back(
        new Object(
            "resources/1942.png",
            Vector2(100, 64),
            Vector2(5, 6),
            Vector2(26, 16),
            RENDERMANAGER.GetRenderer()
    ));

        
    
    textRenderer = new TextRenderer(
        "Pito",
        20,
        SDL_Color{ 150,150,0 },
        new Transform(
            Vector2(256,256), 
            0.0f, 
            Vector2(1.0f,1.0f), 
            Vector2(200,200),
            true),
        "resources/Kaph-Regular.ttf",
        Vector2(0, 0),
        Vector2(100, 100),
        RENDERMANAGER.GetRenderer()
    );

    objects[0]->GetRigidbody()->SetLinearDrag(5);
    objects[0]->SetPosition(Vector2(256, 256));

}

MainMenu::~MainMenu()
{

}

void MainMenu::OnEnter()
{

}

void MainMenu::OnExit()
{

}

void MainMenu::Update(float dt)
{
    for (Object* o : objects)
    {
        o->Update(dt);
    }


   

    Vector2 inputForce = Vector2();

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
        objects.push_back(spawner->SpawnBullet(objects[0]));
    }

    inputForce.Normalize();
    inputForce = inputForce * 30;
    objects[0]->GetRigidbody()->AddForce(inputForce);

}

