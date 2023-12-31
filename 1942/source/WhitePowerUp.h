#pragma once
#include <iostream>
#include "PowerUp.h"

class WhitePowerUp : public PowerUp
{
public:
	WhitePowerUp(Player& p) : PowerUp(p, Vector2(30, 20)) {
		renderer = new ImageRenderer(transform, Vector2(85, 150), Vector2(12, 9));
	}

	void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<Player*>(other))
		{
			SCOREMANAGER.AddScore(100);
			Destroy();
		}
	}
};
