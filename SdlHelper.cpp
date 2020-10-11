#include "SdlHelper.h"

SDL_Texture* SdlHelper::getTexture(std::string filePath, SDL_Renderer* renderer) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath.c_str());
	if (texture == NULL)
		std::cout << "failed to load texture. Error: " << SDL_GetError() << "\n";

	return texture;
}