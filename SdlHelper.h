#pragma once
#include <SDL_image.h>
#include <iostream>
#include "SDL.h"
#include <string>

// TODO: Make it so we don't need to create a new instance everytime.
class SdlHelper
{
public:
	SDL_Texture* getTexture(std::string filePath, SDL_Renderer* renderer);
};

