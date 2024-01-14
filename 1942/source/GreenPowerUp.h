#pragma once

#include "PowerUp.h"


class GreenPowerUp : public PowerUp
{
public:
	GreenPowerUp() : PowerUp(Vector2(30, 20)) {
		renderer = new ImageRenderer(transform, Vector2(68, 150), Vector2(12, 9));
	}
	//void OnCollisionEnter(Object* other) override
	//{
	//	if (dynamic_cast<Player*>(other))
	//	{
	//		SCOREMANAGER.AddScore(100);
	//		//player->isShootingFourBullets = true;
	//		Destroy();
	//	}
	//}
};
