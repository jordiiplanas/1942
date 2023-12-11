#pragma once
#include <SDL_mixer.h>
#include <unordered_map>
#include <queue>
#include <string>
#include <cassert>

#define AUDIOMANAGER AudioManager::GetInstance()

class AudioManager
{
private:
	const int MAX_CHANNELS = 64;
	std::unordered_map<int, Mix_Chunk*> clips;
	std::unordered_map<int, Mix_Music*> songs;
	bool muted;
	std::queue<int> availableIDs;

	AudioManager();
	~AudioManager();
	AudioManager(AudioManager&) = delete;
	AudioManager& operator=(AudioManager&) = delete;

public:
	static AudioManager& GetInstance()
	{
		static AudioManager instance;
		return instance;
	}
	int LoadClip(const std::string path);
	int LoadMusic(const std::string path);
	
	void PlayClip(int id);
	void PlayMusic(int id);

	void StopClip(int id);
	void StopMusic(int id);

	void FreeClip(int id);
	void FreeMusic(int id);

	void Mute();
	void Unmute();
	
	inline bool GetMuted() { return muted; }
};
