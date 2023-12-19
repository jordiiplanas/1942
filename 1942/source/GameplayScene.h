#pragma once
#include "Scene.h"
#include "Player.h"
<<<<<<< HEAD:SDL3/source/GameplayScene.h
=======
#include "Enemy.h"
>>>>>>> main:1942/source/GameplayScene.h

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
<<<<<<< HEAD:SDL3/source/GameplayScene.h
		nextScene = "MainMenu";
		player = new Player("resources/1942.png",
			Vector2(100, 64),
			Vector2(5, 6),
			Vector2(26, 16),
			renderer);
		objects.push_back(player);
=======
		nextScene = "MainMenu";		
		player = new Player(Vector2(250, 350));		
		objects.push_back(player);
		objects.push_back(new Enemy(Vector2(250, 50)));		
>>>>>>> main:1942/source/GameplayScene.h
	}

	void OnEnter() override {}
	void Update(float dt) override;
	
};
