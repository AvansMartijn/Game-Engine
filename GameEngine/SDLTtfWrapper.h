#pragma once
#include <SDL_ttf.h>

struct SDLTtfWrapper {
	SDLTtfWrapper();
	~SDLTtfWrapper();

	SDLTtfWrapper(const SDLTtfWrapper&) = delete;
	SDLTtfWrapper& operator=(const SDLTtfWrapper&) = delete;
	SDLTtfWrapper(SDLTtfWrapper&&) = delete;
	SDLTtfWrapper& operator=(SDLTtfWrapper&&) = delete;
};

