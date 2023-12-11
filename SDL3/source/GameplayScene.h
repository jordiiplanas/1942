#pragma once
#include "Scene.h"

class GameplayScene : public Scene
{
public:
	GameplayScene() : Scene() {
		nextScene = "MainMenu";
	}

	void OnEnter() override {}
	void Update(float dt) override {
		Scene::Update(dt);
		isFinished = inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED);
	}
};
