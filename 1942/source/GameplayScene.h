#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"

class GameplayScene : public Scene
{

private:
	//std::vector<Wave> remainingWaves;
	int levelWaves;
	Player* player;
	float levelTime;
	int rolls;
	int lives;
	//ScoreManager* score
	
public:
	GameplayScene() : Scene() {
		
	}

	void OnEnter() override;
	void Update(float dt) override;
	
};
