#include "SoundFacade.h"

SoundFacade::SoundFacade()
{
    //Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << "\n";
    }

}

bool SoundFacade::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load music
   /* gMusic = Mix_LoadMUS("21_sound_effects_and_music/beat.wav");
    if (gMusic == NULL)
    {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }*/

    //Load sound effects
   /* gScratch = Mix_LoadWAV("21_sound_effects_and_music/scratch.wav");
    if (gScratch == NULL)
    {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }*/

   
    return success;
}

void SoundFacade::close()
{

    ////Free the sound effects
    //Mix_FreeChunk(gScratch);
    //Mix_FreeChunk(gHigh);
    //Mix_FreeChunk(gMedium);
    //Mix_FreeChunk(gLow);
    //gScratch = NULL;
    //gHigh = NULL;
    //gMedium = NULL;
    //gLow = NULL;

    ////Free the music
    //Mix_FreeMusic(gMusic);
    //gMusic = NULL;

    ////Quit SDL subsystems
    //Mix_Quit();
    //SDL_Quit();
}
