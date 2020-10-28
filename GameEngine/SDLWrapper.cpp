#include "pch.h"
#include "SDLWrapper.h"

SDLWrapper::SDLWrapper() {
	SDL_Init(SDL_INIT_VIDEO);
}

SDLWrapper::~SDLWrapper() {
	SDL_Quit();
}