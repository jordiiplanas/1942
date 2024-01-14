#pragma once
#include "Scene.h"
#include "Player.h"
#include "GreenPowerUp.h"
#include "WhitePowerUp.h"
#include "GrayPowerUp.h"
#include "SmallNormalPlane.h"
#include "SmallRedPlane.h"
#include "Background.h"
#include "MediumYellowPlane.h"
#include "BigGreenPlane.h"
#include "Stage.h"
#include "ScoreManager.h"
#include "UiText.h"
#include "IWaveManager.h"

class GameplayScene : public Scene, public IWaveManager
{
private:
	std::vector<Stage*> stages;
	Stage* currentStage;
	bool isEnded = false;
	std::vector<GameObject*> background;
	std::vector<UiText*> deadUi;
	int levelWaves;
	Player* player;
	float levelTime;
	bool playerIsDead;
	SDL_Event event;
	int rolls;
	UiText* scoreUi;
	int lives;
	ScoreManager* score;

	bool hasAlreadyStarted = false;
	bool isPaused = false;

	int spawnedEnemies = 0;
	int killedEnemies = 0;
public:
	GameplayScene() :playerIsDead(false), Scene() {
	};

	void OnEnter() override;
	void Update(float dt) override;
	void Render() override;
	void EndStage();
	
};
