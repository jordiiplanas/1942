#pragma once
#include "Button.h"
#include "AudioManager.h"

class MuteButton : public Button
{
private:
	bool isMuted;
public:
	MuteButton(Vector2 position, std::string buttonText)
		: Button(position, buttonText), isMuted(false) {}

	void Mute()
	{
		if (isMuted)
		{
			std::cout << "Desmuteao" << std::endl;
			AUDIOMANAGER.Unmute();
		}
		else
		{
			std::cout << "Callaito" << std::endl;
			AUDIOMANAGER.Mute();
		}

		isMuted = !isMuted;
	}
};