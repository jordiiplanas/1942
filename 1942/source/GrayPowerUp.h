#pragma once
#include "PowerUp.h"


class GrayPowerUp : public PowerUp
{
public:

	GrayPowerUp(Player& p) : PowerUp(p, Vector2(30, 20)) {
		renderer = new ImageRenderer(transform, Vector2(51,150), Vector2(12,9));
	}

	void OnCollisionEnter(Object* other) override
	{
		if (dynamic_cast<Player*>(other))
		{
			SCOREMANAGER.AddScore(100);
			player->AddSupportPlane();
			Destroy();
		}
	}
};
