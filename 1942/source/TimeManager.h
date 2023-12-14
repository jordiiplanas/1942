#pragma once
#include <SDL.h>

#define TIME TimeManager::Instance()

class TimeManager
{
public:
	inline static TimeManager& Instance()
	{
		static TimeManager timeManager;
		return timeManager;
	}
	void Update();
	inline bool ShouldUpdateGame() { return deltaTime > frameTime; }
	inline void ResetDeltaTime() { deltaTime = 0.0f; }
	inline float GetDeltaTime() const { return deltaTime; }

private:
	TimeManager ()
	{
		deltaTime = 0.0f;
		previousGameTimeInSeconds = (float)SDL_GetPerformanceCounter() / (float)SDL_GetPerformanceFrequency();
		FPS = 60;
		frameTime = 1.f / (float)FPS;
	}
	TimeManager(const TimeManager& timeManager) = delete;
	TimeManager& operator= (const TimeManager& tm) = delete;

	float deltaTime = 0.0f;
	int FPS;
	float frameTime;
	float previousGameTimeInSeconds;
};

void TimeManager::Update()
{
	float gameTime = (float)SDL_GetPerformanceCounter() / (float)SDL_GetPerformanceFrequency();

	deltaTime += gameTime - previousGameTimeInSeconds;
	previousGameTimeInSeconds = gameTime;
}