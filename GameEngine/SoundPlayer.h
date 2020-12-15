#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_SoundPlayer __declspec(dllexport)
#else
#define GAMEENGINE_SoundPlayer __declspec(dllimport)
#endif

#include <map>
#include <SDL_mixer.h>
#include <iostream>

class GAMEENGINE_SoundPlayer SoundPlayer {
private:
	SoundPlayer();
	static SoundPlayer instance;

	// TODO: DEZE WEG WERKEN.
	std::map<std::string, Mix_Music*> _musicTracks;
	std::map<std::string, Mix_Chunk*> _sfx;

	// TODO: DEZE WEG WERKEN.
	/// <summary>
	/// Get's an SFX track.
	/// </summary>
	/// <param name="sfxTrackKey">The track key.</param>
	/// <returns>The SFX track.</returns>
	Mix_Chunk* getSfxTrack(const std::string& sfxTrackKey);

public:
	static SoundPlayer& getInstance() { return instance; }

	SoundPlayer(const SoundPlayer&) = delete;
	SoundPlayer(SoundPlayer&&) = delete;
	SoundPlayer& operator=(const SoundPlayer&) = delete;
	SoundPlayer& operator=(SoundPlayer&&) = delete;

	std::string playingTrackKey;
	int currentVolume = 60;
	int currentSFXVolume = 60;

	/// <summary>
	/// Get's the music track.
	/// </summary>
	/// <param name="musicTrackKey">The music track key.</param>
	/// <returns>The music track.</returns>
	Mix_Music* getMusicTrack(const std::string& musicTrackKey);

	/// <summary>
	/// Adds the music track to the registry.
	/// </summary>
	/// <param name="musicTrackKey">The track key</param>
	/// <param name="musicTrack">The music track</param>
	void registerMusicTrack(const std::string& musicTrackKey, const std::string& musicTrack);
	
	/// <summary>
	/// Adds the SFX track to the registry.
	/// </summary>
	/// <param name="sfxTrackKey">The SFX track</param>
	/// <param name="sfxTrack">The SFX track</param>
	void registerSFXTrack(const std::string& sfxTrackKey, const std::string& sfxTrack);

	/// <summary>
	/// Plays the music track from the registry
	/// </summary>
	/// <param name="musicTrackKey">The track key</param>
	/// <returns></returnsW>
	void playMusicTrack(const std::string& musicTrackKey);

	/// <summary>
	/// Plays the SFX track.
	/// </summary>
	/// <param name="sfxTrackKey">The SFX track key.</param>
	void playSFX(const std::string& sfxTrackKey);

	/// <summary>
	/// Opens the audio channels.
	/// </summary>
	void openAudio();

	/// <summary>
	/// Pauses the music.
	/// </summary>
	void pauseMusic();

	/// <summary>
	/// Changes the music volume.
	/// </summary>
	/// <param name="volume">The volume.</param>
	void changeMusicVolume(int volume);

	/// <summary>
	/// Changes the SFX volume.
	/// </summary>
	/// <param name="volume">The SFX volume.</param>
	void changeSFXVolume(int volume);
};

