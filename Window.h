#pragma once

#define byte win_byte_override

#include "string"
#include "SDL.h"
#include "GameObject.h"
#include "AbstractUiElement.h"
#include "Shapes.h"
#include "SdlHelper.h"
#include "SDL_image.h"
#undef byte

class Window {
public:
	Window(const char* title, int width, int height);
	void cleanUp();
	void clear();
	void render(shared_ptr<GameObject> gameObject);
	void render(shared_ptr<AbstractUiElement> uiElements);
	void display();
	~Window();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

