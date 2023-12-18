#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

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
		player = new Player(Vector2(250, 350));		
		objects.push_back(player);
		objects.push_back(new Enemy(Vector2(250, 50)));		
	}

	void OnEnter() override {}
	void Update(float dt) override;
	
};
