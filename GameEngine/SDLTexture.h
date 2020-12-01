#pragma once
#include <SDL_render.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <iostream>
#include "Rect.h"

class SDLTexture
{
public:
	int width;
	int height;

	SDLTexture(std::string filePath, SDL_Renderer* renderer);
	~SDLTexture();

	void renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft);
private:
	SDL_Texture* _texture;
};

