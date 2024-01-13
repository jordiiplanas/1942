#pragma once
#include "Wave.h"

class Stage
{
private:
	std::vector<Wave*> waves;
	float totalTime;

	float currentTime;
	bool isFinished;
public:
	Stage(int totalTime)
	{
			this->totalTime = totalTime;
			currentTime = 0;
			isFinished = false;
	}
	inline void SetWaves(std::vector<Wave*> waves)
	{
		this->waves = waves;
	}
	void Update(float dt)
	{
		if (isFinished)
		{
			return;
		}
		
		currentTime += dt;

		if (currentTime >= totalTime)
		{
			isFinished = true;
			return;
		}
		
		/*for (Wave wave : waves)
		{
			if (wave.GetStartTime() >= currentTime)
				wave.Update(dt);
		}*/
	}
};