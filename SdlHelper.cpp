#include "SdlHelper.h"

SDL_Texture* SdlHelper::getTexture(std::string filePath, SDL_Renderer* renderer) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath.c_str());
	if (texture == NULL)
		std::cout << "failed to load texture. Error: " << SDL_GetError() << "\n";

	return texture;
}

void SdlHelper::renderText(std::string text, TTF_Font* font, SDL_Rect* rectangle, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture, bool center) {
    SDL_Rect rect;
    rect.x = rectangle->x;
    rect.y = rectangle->y;
    rect.w = surface->w;
    rect.h = surface->h;

    // TODO: Move the resolution to a different class.
    if (center)
        rect.x = (1080 / 2) - (rect.w / 3);

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}