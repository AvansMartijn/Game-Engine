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

void SDLTexture::renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft, int alpha) {
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

	SDL_RenderCopyEx(renderer, _texture, NULL, &sdlRect, (double)angle, NULL, flip);

}

void SDLTexture::renderSprite(SDL_Renderer* renderer, Rect rect, Rect spriteRect, int angle, bool flipLeft) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;
	SDL_Point centerPoint = { sdlRect.x + (sdlRect.w / 2), sdlRect.y + (sdlRect.h / 2) };
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	if (!flipLeft)
		flip = SDL_FLIP_NONE;

	SDL_Rect sdlSpriteRect;
	sdlSpriteRect.x = spriteRect.x;
	sdlSpriteRect.y = spriteRect.y;
	sdlSpriteRect.w = spriteRect.w;
	sdlSpriteRect.h = spriteRect.h;

	SDL_RenderCopyEx(renderer, _texture, &sdlSpriteRect, &sdlRect, (double)angle, NULL, flip);
}