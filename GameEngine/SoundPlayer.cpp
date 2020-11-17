#include "pch.h"
#include "SoundPlayer.h"

SoundPlayer SoundPlayer::instance;

SoundPlayer::SoundPlayer() {}

void SoundPlayer::registerMusicTrack(const std::string& musicTrackKey, const std::string& musicTrack)
{
	_musicTracks.insert(std::pair<std::string, Mix_Music*>(musicTrackKey, Mix_LoadMUS(musicTrack.c_str())));
}

void SoundPlayer::registerSFXTrack(const std::string& musicTrackKey, const std::string& musicTrack)
{
	_sfx.insert(std::pair<std::string, Mix_Chunk*>(musicTrackKey, Mix_LoadWAV(musicTrack.c_str())));
}

Mix_Music* SoundPlayer::getMusicTrack(const std::string& musicTrackKey)
{
	return _musicTracks[musicTrackKey];
}

Mix_Chunk* SoundPlayer::getSfxTrack(const std::string& sfxTrackKey)
{
	return _sfx[sfxTrackKey];
}

void SoundPlayer::pauseMusic() {
	if (Mix_PausedMusic() == 1)
	{
		//Resume the music
		Mix_ResumeMusic();
	}
	//If the music is playing
	else
	{
		//Pause the music
		Mix_PauseMusic();
	}
}

void SoundPlayer::playMusicTrack(const std::string& musicTrackKey)
{
	
	Mix_Music* musicTrack = getMusicTrack(musicTrackKey);
	Mix_PlayMusic(musicTrack, -1);
	
}

void SoundPlayer::playSFX(const std::string& sfxTrackKey)
{
	Mix_Chunk* sfx = getSfxTrack(sfxTrackKey);
	Mix_PlayChannel(-1, sfx, 0);
}

void SoundPlayer::openAudio()
{
	//Initialize Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	Mix_VolumeMusic(60);
}
