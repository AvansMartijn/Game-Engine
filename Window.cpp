#pragma once
#include "Window.h"
#include "Windows.h"
#include "Shapes.h"
#include "SDL_image.h"
#include <iostream>

Window::Window(const std::string& title, int width, int height) :_title(title), _width(width), _height(height) {

	_closed = !init();
}

// Deconstructer
Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Window::pollEvents()
{
	// Hier kan je alle events pollen en toevoegen
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_closed = true;
			break;
		case SDL_KEYDOWN:
			g_ShapeDrawer.drawImage(Window::_renderer, "res/WUAH.png", 0, 250, 250, 250);
			break;
		default:
			break;
		}
	}
}

void Window::clear() const
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	//SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
	g_ShapeDrawer.drawCube(Window::_renderer, SDL_Color{ 0, 255, 255 }, 0, 250, 250, 250);

	//g_ShapeDrawer.DrawImage(Window::_renderer, "res/WUAH.png", 0, 250, 250, 250);
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to init SDL \n";
		return false;	
	}

	/*if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Failed to init image lib \n";
		return false;
	}*/

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
	std::cout << "Creating Window \n";

	if (_window == nullptr) {
		std::cerr << "Failed to create window \n";
		return false;
	}

	// Init van de renderer
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC); /// Kijken welke enum het snelste is voor het drawen van de game zelf heb ik geen vsync nodig

	return true;
}
