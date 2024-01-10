<<<<<<< HEAD:SDL3/source/MainMenu.h
﻿#pragma once
#include "Scene.h"
#include "Enemy.h"
#include "Player.h"
#include "AudioManager.h"

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
=======
﻿#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"
#include "AudioManager.h"

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
>>>>>>> main:1942/source/MainMenu.h
