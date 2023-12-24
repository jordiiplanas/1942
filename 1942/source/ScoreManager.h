#pragma once
#include "UiText.h"
class ScoreManager
{
private:
	int score;
	UiText* uiScore;
public:
	ScoreManager(UiText* uiScore) : score(0), uiScore(uiScore) {}
	void AddScore(int amount) 
	{ 
		score += amount;
		std::string texto = "SCORE" + score;
		uiScore->ChangeText(texto);
	}
	int GetScore() { return score; }
};

