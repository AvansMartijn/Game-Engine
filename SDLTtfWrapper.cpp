#include "SDLTtfWrapper.h"
#include <iostream>
SDLTtfWrapper::SDLTtfWrapper() {
	TTF_Init();
}

SDLTtfWrapper::~SDLTtfWrapper() {
	TTF_Quit();
}