#pragma once
#include <SDL.H>

struct SDLWrapper
{
	SDLWrapper();
	~SDLWrapper();

	SDLWrapper(const SDLWrapper&) = delete;
	SDLWrapper& operator=(const SDLWrapper&) = delete;
	SDLWrapper(SDLWrapper&&) = delete;
	SDLWrapper& operator=(SDLWrapper&&) = delete;
};

