#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class SoundFacade
{
	//The music that will be played
	Mix_Music* gMusic = NULL;

	//The sound effects that will be used
	/*Mix_Chunk* gScratch = NULL;
	Mix_Chunk* gHigh = NULL;
	Mix_Chunk* gMedium = NULL;
	Mix_Chunk* gLow = NULL;*/

	SoundFacade();
	bool loadMedia();
	void close();
};

