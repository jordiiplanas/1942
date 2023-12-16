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

		player = new Player("resources/1942.png",
			Vector2(100, 64),
			Vector2(5, 6),
			Vector2(26, 16)
		);
		player->GetRigidbody()->SetLinearDrag(4);
		player->SetPosition(Vector2(250, 350));
		objects.push_back(player);

		objects.push_back(new Enemy(2, 20, "resources/1942.png",
			Vector2(100, 64),
			Vector2(5, 200),
			Vector2(15, 14)));
	}

	void OnEnter() override {}
	void Update(float dt) override;
	
};
