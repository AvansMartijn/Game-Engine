#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>

class SdlHelper
{
public:
	SDL_Texture* getTexture(std::string filePath, SDL_Renderer* renderer);
	void renderText(std::string text, TTF_Font* font, SDL_Rect* rectangle, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture, bool center);
};

