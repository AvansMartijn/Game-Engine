#pragma once
#include "Window.h"
#include "Windows.h"
#include "Shapes.h"
#include "SDL_image.h"
#include <iostream>

//Shapes g_ShapeDrawer;

Window::Window(const char* title, int width, int height): _window(NULL), _renderer(NULL) {

	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (_window == NULL) {
		std::cout << "Window failed to init. Error: " << SDL_GetError() << "\n";
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);


	//_closed = !init();
}

// Deconstructer
Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

//bool Window::init()
//{
//	return true;
//}

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

void Window::render(const shared_ptr<GameObject>& gameObject) {
	Vec2 pos;
	Vec2 size;
	pos.x = gameObject->physicalBody.body.position.x;
	pos.y = gameObject->physicalBody.body.position.y;
	size.x = gameObject->physicalBody.shape.max.x - gameObject->physicalBody.shape.min.x;
	size.y = gameObject->physicalBody.shape.max.y - gameObject->physicalBody.shape.min.y;
	SDL_Color color = { 255, 0, 0, 255 };
	g_ShapeDrawer.drawCube(_renderer, color, pos.x, pos.y, size.x, size.y);

	//SDL_RenderCopy(_renderer, NULL, rect)
}

void Window::display() {
	SDL_RenderPresent(_renderer);
}


//void Window::pollEvents()
//{
//	// Hier kan je alle events pollen en toevoegen
//	SDL_Event event;
//
//	if (SDL_PollEvent(&event)) {
//		switch (event.type) {
//		case SDL_QUIT:
//			_closed = true;
//			break;
//		case SDL_KEYDOWN:
//			g_ShapeDrawer.drawImage(Window::_renderer, "res/WUAH.png", 0, 250, 250, 250);
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void Window::clear() const
//{
//	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
//	//SDL_RenderClear(_renderer);
//	SDL_RenderPresent(_renderer);
//	g_ShapeDrawer.drawCube(Window::_renderer, SDL_Color{ 0, 255, 255 }, 0, 250, 250, 250);
//
//	//g_ShapeDrawer.DrawImage(Window::_renderer, "res/WUAH.png", 0, 250, 250, 250);
//}
//
//bool Window::init()
//{
//	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//		std::cerr << "Failed to init SDL \n";
//		return false;	
//	}
//
//	/*if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
//		std::cerr << "Failed to init image lib \n";
//		return false;
//	}*/
//
//	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
//	std::cout << "Creating Window \n";
//
//	if (_window == nullptr) {
//		std::cerr << "Failed to create window \n";
//		return false;
//	}
//
//	// Init van de renderer
//	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC); /// Kijken welke enum het snelste is voor het drawen van de game zelf heb ik geen vsync nodig
//
//	return true;
//}
