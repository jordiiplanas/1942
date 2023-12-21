#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "GreenPowerUp.h"
#include "WhitePowerUp.h"
#include "GrayPowerUp.h"
class GameplayScene : public Scene
{

private:
	//std::vector<Wave> remainingWaves;
	int levelWaves;
	Spawner spawner;
	Player* player;
	float levelTime;
	int rolls;
	int lives;
	//ScoreManager* score
	
public:
	GameplayScene() : Scene() {
		nextScene = "MainMenu";		
		player = new Player(Vector2(250, 20));		
		objects.push_back(player);
		objects.push_back(new Enemy(2, 400, &spawner, player->GetTransform()));		
		objects.push_back(new WhitePowerUp(*player));
	}

	void OnEnter() override {}
	void Update(float dt) override;
	
};
