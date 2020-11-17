#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_SoundPlayer __declspec(dllexport)
#else
#define GAMEENGINE_SoundPlayer __declspec(dllimport)
#endif

#include <map>
#include <SDL_mixer.h>
#include <iostream>

class GAMEENGINE_SoundPlayer SoundPlayer
{
private:
	SoundPlayer();
	static SoundPlayer instance;
	std::map<std::string, Mix_Music*> _musicTracks;
	std::map<std::string, Mix_Chunk*> _sfx;
	Mix_Chunk* getSfxTrack(const std::string& sfxTrackKey);

public:
	static SoundPlayer& getInstance() { return instance; }

	SoundPlayer(const SoundPlayer&) = delete;
	SoundPlayer(SoundPlayer&&) = delete;
	SoundPlayer& operator=(const SoundPlayer&) = delete;
	SoundPlayer& operator=(SoundPlayer&&) = delete;

	std::string playingTrackKey;
	Mix_Music* getMusicTrack(const std::string& musicTrackKey);
	/// <summary>
	/// Adds the music track to the registry.
	/// </summary>
	/// <param name="musicTrackKey">The track key</param>
	/// <param name="musicTrack">The music track</param>
	void registerMusicTrack(const std::string& musicTrackKey, const std::string& musicTrack);
	
	void registerSFXTrack(const std::string& musicTrackKey, const std::string& musicTrack);

	/// <summary>
	/// Gets the music track from the registry
	/// </summary>
	/// <param name="musicTrackKey">The track key</param>
	/// <returns></returnsW>

	void playMusicTrack(const std::string& musicTrackKey);


	void playSFX(const std::string& sfxTrackKey);

	void openAudio();

	void pauseMusic();

	void changeMusicVolume(int volume);

};

