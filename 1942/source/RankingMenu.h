#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"
#include "AudioManager.h"
#include "Button.h"


class RankingMenu : public Scene
{
private:
    float gameTime = 0;
    int sfxID;

public:
    RankingMenu();
    ~RankingMenu();
    virtual void OnEnter() override;
    virtual void Update(float dt) override;
    virtual void Render() override;
};

