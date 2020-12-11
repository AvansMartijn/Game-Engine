#pragma once
#include <SDL_render.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <iostream>
#include "Rect.h"
#include <map>
#include <vector>

class SDLTexture
{
public:
	bool isReversed;

	SDLTexture(std::string filePath, SDL_Renderer* renderer);
	~SDLTexture();

	void renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft, int alpha = 0);
	void renderSprite(SDL_Renderer* renderer, Rect rect, Rect spriteRect, int angle, bool flipLeft);
private:
	SDL_Texture* _texture;
};

