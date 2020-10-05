#pragma once
#include "Window.h"
#include "Windows.h"
#include "Shapes.h"
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

void Window::PollEvents()
{
	// Hier kan je alle events pollen en toevoegen
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_closed = true;
			break;
		default:
			break;
		}
	}
}

void Window::clear() const
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);

	SDL_Color green{ 0, 255, 0 ,255 };

	g_ShapeDrawer.DrawCube(_renderer, green, 120, 120, 100, 100);
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Failed to init SDL \n";
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
	std::cout << "Creating Window \n";

	if (_window == nullptr) {
		std::cout << "Failed to create window \n";
		return false;
	}

	// Init van de renderer
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC); /// Kijken welke enum het snelste is voor het drawen van de game zelf heb ik geen vsync nodig

	return true;
}
