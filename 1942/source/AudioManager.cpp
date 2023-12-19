#include "AudioManager.h"

AudioManager::AudioManager()
{
    muted = false;
    assert(!Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) >= 0);
    for (int i = 0; i < 1024; i++) {
        availableIDs.push(i);
    }
}

AudioManager::~AudioManager()
{
    for (auto clip : clips) {
		Mix_FreeChunk(clip.second);
	}
    clips.clear();

    for (auto song : songs) {
        Mix_FreeMusic(song.second);
    }
    
    Mix_CloseAudio();
}

int AudioManager::LoadClip(const std::string path)
{
    Mix_Chunk* sfx = Mix_LoadWAV(path.c_str());
    assert(sfx);
    
    int id = availableIDs.front();
    clips.emplace(id, sfx);
    
    availableIDs.pop();

    return id;
}

int AudioManager::LoadMusic(const std::string path)
{
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    assert(music);

    int id = availableIDs.front();
    songs.emplace(id, music);

    availableIDs.pop();

    return id;
}

void AudioManager::PlayClip(int id)
{
    Mix_PlayChannel(id, clips[id], 0);
}

void AudioManager::PlayMusic(int id)
{
    Mix_FadeInMusic(songs[id], id, 500);
}

void AudioManager::StopClip(int id)
{
    Mix_HaltChannel(id);
	availableIDs.push(id);
}

void AudioManager::StopMusic(int id)
{
    Mix_FadeOutChannel(id, 500);
}

void AudioManager::FreeClip(int id)
{
	availableIDs.push(id);
	Mix_FreeChunk(clips[id]);
	clips.erase(id);
}

void AudioManager::FreeMusic(int id)
{
	availableIDs.push(id);
    Mix_FreeMusic(songs[id]);
	songs.erase(id);
}

void AudioManager::Mute()
{
    /*Mix_HaltChannel(-1);
    Mix_HaltMusic();*/
    Mix_Volume(-1, 0);
    muted = true;
}

void AudioManager::Unmute()
{
    Mix_Volume(-1, MIX_MAX_VOLUME);
    muted = false;
}
