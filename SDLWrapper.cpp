#include "SDLWrapper.h"
#include <iostream>
SDLWrapper::SDLWrapper() 
{
	std::cout << "CREATE\n";
	SDL_Init(SDL_INIT_VIDEO);
}

SDLWrapper::~SDLWrapper() {
	std::cout << "DESTROY\n";
	SDL_Quit();
}