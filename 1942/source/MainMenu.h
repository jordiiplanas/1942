#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"
#include "AudioManager.h"
#include "LoadSceneButton.h"
#include "MuteButton.h"
#include "ExitButton.h"


class MainMenu : public Scene
{
private:
    float gameTime = 0;
    Player* player;
    int sfxID;

public:
    MainMenu();
    ~MainMenu();
    virtual void OnEnter() override;
    virtual void Update(float dt) override;
    virtual void Render() override;
};
