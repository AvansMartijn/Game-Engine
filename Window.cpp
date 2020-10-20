#pragma once
#include "Window.h"
#include "Windows.h"

Window::Window(const char* title, int width, int height): _path {title} {

	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	_window.reset(window);
	_renderer.reset(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

	//_renderer.reset(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));
	//if (_window == NULL)
	//	std::cout << "Window failed to init. Error: " << SDL_GetError() << "\n";

	//if (TTF_Init() < 0)
	//	printf("TTF_Init: %s\n", TTF_GetError());

	//_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::update() const {
	SDL_RenderClear(_renderer.get());
	SDL_RenderCopy(_renderer.get(), _texture.get(), nullptr, nullptr);
	SDL_RenderPresent(_renderer.get());
}

void Window::loadImage() {

}

// TODO: Als het goed is is dit niet meer nodig.
//Window::~Window(){
//	SDL_DestroyRenderer(_renderer.get());
//	SDL_DestroyWindow(_window.get());
//	SDL_Quit();
//}
//

void Window::cleanUp() {
	SDL_DestroyWindow(_window.get());
}

void Window::clear() {
	SDL_SetRenderDrawColor(_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer.get());
}

void Window::render(shared_ptr<GameObject> gameObject) {
	SDL_Rect dst;
	dst.x = gameObject->physicalBody.body.position.x;
	dst.y = gameObject->physicalBody.body.position.y;
	dst.w = gameObject->physicalBody.shape.getWidth();
	dst.h = gameObject->physicalBody.shape.getHeight();

	SDL_RenderCopy(_renderer.get(), gameObject->texture, NULL, &dst);
}

//void Window::render(shared_ptr<AbstractUiElement> uiElement) {
//	uiElement->render(_window);
//}
//
//void Window::preRender(shared_ptr<GameObject> gameObject) {
//	gameObject->preRender(_renderer.get());
//}
//
//void Window::preRender(shared_ptr<AbstractUiElement> uiElement) {
//	uiElement->preRender(_renderer.get());
//}

void Window::display() {
	SDL_RenderPresent(_renderer.get());
}
