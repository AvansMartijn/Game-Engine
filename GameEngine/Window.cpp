#pragma once

#include "pch.h"
#include "Window.h"
#include <windows.h>

Window::Window(const char* title, int width, int height) {
	_width = width;
	_height = height;

	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	_window.reset(window);
	_renderer.reset(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));
}

int Window::getWidth() const {
	return _width;
}

int Window::getHeight() const {
	return _height;
}

void Window::registerTexture(std::string textureKey, std::string texturePath) {
	_assetRegistry.registerTexture(textureKey, getTexture(texturePath));
}

void Window::registerFont(std::string fontKey, std::string fontPath) {
	_assetRegistry.registerFont(fontKey, fontPath);
}

SDL_Texture* Window::getTexture(std::string filePath) const {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(_renderer.get(), filePath.c_str());
	if (texture == NULL)
		std::cout << "failed to load texture. Error: " << SDL_GetError() << "\n";

	return texture;
}

TTF_Font* Window::getFont(std::string fontKey, int fontSize) {
	return TTF_OpenFont(_assetRegistry.getFontPath(fontKey.c_str()).c_str(), fontSize);
}

void Window::clear() {
	SDL_SetRenderDrawColor(_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer.get());
}

void Window::renderRectangle(Rect rect, Color color) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;

	SDL_SetRenderDrawColor(_renderer.get(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(_renderer.get(), &sdlRect);
}

void Window::renderTexture(std::string textureKey, Rect rect) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;

	SDL_RenderCopy(_renderer.get(), _assetRegistry.getTexture(textureKey), NULL, &sdlRect);
}

void Window::renderText(std::string text, TTF_Font* font, Rect rect, Color foregroundColor, Color backgroundColor, bool center) {
	SDL_Color sdlForegroundColor = { foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a };
	SDL_Color sdlBackgrouldColor = { backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a };

	SDL_Surface* surface = TTF_RenderText_Shaded(font, text.c_str(), sdlForegroundColor, sdlBackgrouldColor);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);

	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = surface->w;
	sdlRect.h = surface->h;

	if (center) {
		int txtWidth;
		int txtHeight;
		if (TTF_SizeText(font, text.c_str(), &txtWidth, &txtHeight))
			cout << TTF_GetError();
		else
			sdlRect.x = (getWidth() / 2) - (txtWidth / 2);
	}

	SDL_RenderCopy(_renderer.get(), texture, NULL, &sdlRect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Window::display() {
	SDL_RenderPresent(_renderer.get());
}