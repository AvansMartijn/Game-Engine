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

class SDLTexture {
private:
	SDL_Texture* _texture;
public:
	bool isReversed;

	SDLTexture(std::string filePath, SDL_Renderer* renderer);
	~SDLTexture();

	/// <summary>
	/// Render the texture.
	/// </summary>
	/// <param name="renderer">The renderer which we want to use.</param>
	/// <param name="rect">The rectangle we want to draw in.</param>
	/// <param name="angle">The angle which we want to draw.</param>
	/// <param name="flipLeft">If we should flip the texture.</param>
	/// <param name="alpha">The transparency</param>
	void renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft, int alpha = 0);

	/// <summary>
	/// Render the texture.
	/// </summary>
	/// <param name="renderer">The renderer which we want to use.</param>
	/// <param name="rect">The rectangle we want to draw in.</param>
	/// <param name="spriteRect">The rect which the sprite is in.</param>
	/// <param name="angle">The angle which we want to draw.</param>
	/// <param name="flipLeft">If we should flip the texture.</param>
	void renderSprite(SDL_Renderer* renderer, Rect rect, Rect spriteRect, int angle, bool flipLeft);
};

