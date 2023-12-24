#pragma once
#include "UiText.h"
#define SCOREMANAGER ScoreManager::GetInstance()

class ScoreManager
{
private:
	ScoreManager() : score(0){}
	//~ScoreManager();
	ScoreManager(ScoreManager&) = delete;
	ScoreManager& operator=(ScoreManager&) = delete;
	int score;
	UiText* uiScore;
public:
	static ScoreManager& GetInstance() {
		static ScoreManager instance;
		return instance;
	}
	void AddScore(int amount) 
	{ 
		score += amount;
		std::string texto = "SCORE" + score;
	}
	int GetScore() { return score; }
};

