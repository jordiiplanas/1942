#pragma once
#include "GameObject.h"

class SuperKiller : public GameObject
{
private:
	float timePassed;
	float timeToDisappear;
public:
	SuperKiller(float time) : GameObject(Vector2(512, 512)), timeToDisappear(time)
	{
		timePassed = 0;
	}
	virtual void Update(float dt) override
	{
		timePassed += dt;
		if (timePassed >= timeToDisappear)
		{
			Destroy();
		}
	}
	virtual void Render() override
	{
		//Hidden 
	}
};