#pragma once
#include <iostream>
#include "PowerUp.h"

class WhitePowerUp : public PowerUp
{
public:
	WhitePowerUp(Player& p, ScoreManager* scoreManager) : PowerUp(p, Vector2(30, 20), scoreManager) {
		renderer = new ImageRenderer(transform, Vector2(85, 150), Vector2(12, 9));
	}
};
