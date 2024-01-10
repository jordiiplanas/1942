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
#include "Wave.h"
#include "ScoreManager.h"
#include "UiText.h"

class GameplayScene : public Scene
{
private:
	std::vector<Wave*> waves;
	int waveIndex;
	std::vector<Object*> background;
	int levelWaves;
	Player* player;
	float levelTime;
	int rolls;
	UiText* scoreUi;
	int lives;
	ScoreManager* score;
public:
	GameplayScene() : Scene() {
	};

	void OnEnter() override;
	void Update(float dt) override;
	void Render() override;
	
};
