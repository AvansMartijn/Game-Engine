#pragma once

#define byte win_byte_override

#include "string"
#include "SDL.h"
#include "GameObject.h"
#include "Shapes.h"

#undef byte

class Window {
public:
	Window(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(shared_ptr<GameObject> gameObject);
	void display();
	~Window();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

