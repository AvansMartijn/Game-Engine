#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class SoundFacade
{
	/// <summary>
	/// Background Music
	/// </summary>
	Mix_Music* gMusic = NULL;

	//The sound effects that will be used
	/*Mix_Chunk* gScratch = NULL;
	Mix_Chunk* gHigh = NULL;
	Mix_Chunk* gMedium = NULL;
	Mix_Chunk* gLow = NULL;*/

	SoundFacade();
	/// <summary>
	/// Load the music files.
	/// </summary>
	/// <returns>true if success, false if fail.</returns>
	bool loadMedia();
	/// <summary>
	/// Free all resources.
	/// </summary>
	void close();
};

