#pragma once
#include "Button.h"
#include "InputManager.h"

class ExitButton : public Button
{
private:
	bool isMuted;
public:
	ExitButton(Vector2 position, std::string buttonText)
		: Button(position, buttonText), isMuted(false) {}

	void Exit()
	{
		inputManager.SetQuitEvent(true);
	}
};