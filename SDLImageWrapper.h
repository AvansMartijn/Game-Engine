#pragma once
#include <SDL_image.H>
#include <stdexcept>

struct SDLImageWrapper
{
	SDLImageWrapper();
	~SDLImageWrapper();

	SDLImageWrapper(const SDLImageWrapper&) = delete;
	SDLImageWrapper& operator=(const SDLImageWrapper&) = delete;
	SDLImageWrapper(SDLImageWrapper&&) = delete;
	SDLImageWrapper& operator=(SDLImageWrapper&&) = delete;
};

