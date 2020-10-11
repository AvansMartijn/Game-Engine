#pragma once
#include "Window.h"
#include "Windows.h"

#include <iostream>

Window::Window(const char* title, int width, int height): _window(NULL), _renderer(NULL) {

	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (_window == NULL)
		std::cout << "Window failed to init. Error: " << SDL_GetError() << "\n";

	if (TTF_Init() < 0)
		printf("TTF_Init: %s\n", TTF_GetError());

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window(){
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
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

	SDL_RenderCopy(_renderer, gameObject->texture, NULL, &dst);
}

void Window::render(shared_ptr<AbstractUiElement> uiElement) {
	uiElement->render(_renderer);
}

void Window::preRender(shared_ptr<GameObject> gameObject) {
	gameObject->preRender(_renderer);
}

void Window::preRender(shared_ptr<AbstractUiElement> uiElement) {
	uiElement->preRender(_renderer);
}

void Window::display() {
	SDL_RenderPresent(_renderer);
}
