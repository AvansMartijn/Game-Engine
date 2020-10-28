#include "pch.h"
#include "SDLImageWrapper.h"

SDLImageWrapper::SDLImageWrapper() {
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	int result = IMG_Init(flags);

	if ((result & flags) != flags)
		throw std::runtime_error(IMG_GetError());
}

SDLImageWrapper::~SDLImageWrapper() {
	IMG_Quit();
}