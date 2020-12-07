#include "pch.h"
#include "SDLTexture.h"


SDLTexture::SDLTexture(std::string filePath, SDL_Renderer* renderer) {
	_texture = IMG_LoadTexture(renderer, filePath.c_str());
	if (_texture == NULL)
		std::cout << "failed to load texture. Error: " << SDL_GetError() << "\n";
}

SDLTexture::~SDLTexture() {
	// TODO: Destroy
}

void SDLTexture::renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft, std::string spriteKey, int alpha) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;
	SDL_Point centerPoint = { sdlRect.x + (sdlRect.w / 2), sdlRect.y + (sdlRect.h / 2) };
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	if (!flipLeft)
		flip = SDL_FLIP_NONE;

	if(alpha > 0)
		SDL_SetTextureAlphaMod(_texture, alpha);

	if (spriteKey != "") {
		SDL_Rect srcRect = { sprites[spriteKey].x, sprites[spriteKey].y, sprites[spriteKey].w, sprites[spriteKey].h };

		SDL_RenderCopyEx(renderer, _texture, &srcRect, &sdlRect, (double)angle, NULL, flip);
	}
	else
		SDL_RenderCopyEx(renderer, _texture, NULL, &sdlRect, (double)angle, NULL, flip);

}