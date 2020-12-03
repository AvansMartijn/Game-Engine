#pragma once
#include <SDL_render.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <iostream>
#include "Rect.h"
#include <map>

class SDLTexture
{
public:
	std::map<std::string, Rect> sprites;
	bool isSpriteSheet;

	SDLTexture(std::string filePath, SDL_Renderer* renderer);
	~SDLTexture();

	void renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft, std::string spriteKey = "");
private:
	SDL_Texture* _texture;
};

