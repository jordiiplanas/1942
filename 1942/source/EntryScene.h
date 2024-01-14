#pragma once
#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"
#include "AudioManager.h"
#include "Button.h"
#include "Presentation.h"


class EntryScene : public Scene
{
private:
    float gameTime = 0;
    int sfxID;
    float timeDuration = 3;
    float actualTime = 0;
    

public:
    EntryScene();
    ~EntryScene();
    virtual void OnEnter() override;
    virtual void Update(float dt) override;
    virtual void Render() override;
};