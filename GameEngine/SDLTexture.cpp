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

void SDLTexture::renderTexture(SDL_Renderer* renderer, Rect rect, float angle, bool flipLeft) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;
	SDL_Point centerPoint = { sdlRect.x + (sdlRect.w / 2), sdlRect.y + (sdlRect.h / 2) };
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	if (!flipLeft)
		flip = SDL_FLIP_NONE;

	SDL_RenderCopyEx(renderer, _texture, NULL, &sdlRect, (double)angle, NULL, flip);
	//_texture->
	//// TODO: Please add a debug variable, these can get really annoying.
	//Color color1 = { 255, 0, 0, 1 };
	//Rect centerrect = { centerPoint.x, centerPoint.y, 2, 2 };
	//renderRectangle(centerrect, color1);
	//Color color2 = { 255, 0, 0, 1 };
	//Rect leftuprect = { rect.x, rect.y, 2, 2 };
	//renderRectangle(leftuprect, color2);
	//Color color3 = { 255, 0, 0, 1 };
	//Rect rightuprect = { rect.x + rect.w,  rect.y, 2, 2 };
	//renderRectangle(rightuprect, color3);
	//Color color4 = { 255, 0, 0, 1 };
	//Rect leftdownrect = { rect.x,  rect.y + rect.h, 2, 2 };
	//renderRectangle(leftdownrect, color4);
	//Color color5 = { 255, 0, 0, 1 };
	//Rect rightdownrect = { rect.x + rect.w,  rect.y + rect.h, 2, 2 };
	//renderRectangle(rightdownrect, color5);
}