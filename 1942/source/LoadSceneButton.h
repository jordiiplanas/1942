#pragma once
#include "Button.h"

class LoadSceneButton : public Button
{
private:
	std::string sceneName;
public:
	LoadSceneButton(Vector2 position, std::string buttonText, std::string sceneName)
		: Button(position, buttonText), sceneName(sceneName) {}

	std::string GetSceneName() { return sceneName; }
};