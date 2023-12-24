#pragma once
#include "Scene.h"
#include "Player.h"
#include "GreenPowerUp.h"
#include "WhitePowerUp.h"
#include "GrayPowerUp.h"
#include "SmallNormalPlane.h"
#include "Background.h"
class GameplayScene : public Scene
{

private:
	std::vector<Object*> background;
	int levelWaves;
	Player* player;
	float levelTime;
	int rolls;
	int lives;
	//ScoreManager* score
	
public:
	GameplayScene() : Scene() {};

	void OnEnter() override;
	void Update(float dt) override;
	void Render() override;
	
};
