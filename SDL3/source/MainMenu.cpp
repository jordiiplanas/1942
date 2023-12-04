#include "MainMenu.h"

#include <iostream>

#include "InputManager.h"

MainMenu::MainMenu()
{
    objects.push_back(
        new Object(
        "resources/1942.png", 
        Vector2(100,64),
        Vector2(5,6),
        Vector2(26,16),
        RENDERMANAGER.GetRenderer()));

    objects[0]->GetRigidbody()->SetLinearDrag(5);
    objects[0]->SetPosition(Vector2(256,256));
    objects[0]->SetRotation(50);
    
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
    Scene::Update(dt);

    // Que la imatge es mogui en un cercle que
    // te en el centre al mig de la pantalla i
    // 100 px de radi

    /*gameTime += dt;
    objects[0]->SetPosition(Vector2(
        256 + cos(gameTime * M_PI * 2) * 100,
        256 + sin(gameTime * M_PI * 2) * 100
    ));*/

    //if (objects[0]->GetRigidbody()->CheckOverlappingPoint(
    //            Vector2(inputManager.GetMouseX(), inputManager.GetMouseY())))
    //{
    //    //objects[0]->SetRotation(objects[0]->GetRotation() + 150 * dt);
    //    std::cout << "Me pican los cocos aaaa" << std::endl;
    //}

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
    inputForce.Normalize();
    inputForce = inputForce * 30;
    objects[0]->GetRigidbody()->AddForce(inputForce);

}

