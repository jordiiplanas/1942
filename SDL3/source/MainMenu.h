#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
private:
    float gameTime = 0;
public:
    MainMenu();
    ~MainMenu();
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void Update(float dt) override;
};
