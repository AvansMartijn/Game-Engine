#pragma once
#include "Window.h"
#include "Windows.h"
#include "Shapes.h"
#include "SDL_image.h"
#include <iostream>

SDL_Texture* Krool;

Window::Window(const char* title, int width, int height): _window(NULL), _renderer(NULL) {

	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (_window == NULL) {
		std::cout << "Window failed to init. Error: " << SDL_GetError() << "\n";
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	Krool = loadTexture("res/gfx/KINGKROOL.png");

}

Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

SDL_Texture* Window::loadTexture(const char* filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(_renderer, filePath);
	if (texture == NULL) {
		std::cout << "failed to load texture. Error: " << SDL_GetError() << "\n";
	}
	return texture;
	
}

void Window::cleanUp() {
	SDL_DestroyWindow(_window);
}

void Window::clear() {
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);
}

void Window::render(shared_ptr<GameObject> gameObject) {
	SDL_Rect dst;
	dst.x = gameObject->physicalBody.body.position.x;
	dst.y = gameObject->physicalBody.body.position.y;
	dst.w = gameObject->physicalBody.shape.getWidth();
	dst.h = gameObject->physicalBody.shape.getHeight();

	SDL_RenderCopy(_renderer, Krool, NULL, &dst);
}

void Window::display() {
	SDL_RenderPresent(_renderer);
}
