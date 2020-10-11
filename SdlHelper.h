#pragma once
#include <SDL_image.h>
#include <iostream>
#include "SDL.h"
#include <string>
class SdlHelper
{
public:
	SDL_Texture* getTexture(std::string filePath, SDL_Renderer* renderer);
};

