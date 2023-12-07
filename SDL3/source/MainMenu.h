#pragma once
#include "Scene.h"
#include "Player.h"

class MainMenu : public Scene
{
private:
    float gameTime = 0;
    Player* player;

public:
    MainMenu();
    ~MainMenu();
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void Update(float dt) override;
};
