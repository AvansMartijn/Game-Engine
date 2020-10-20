#pragma once

#define byte win_byte_override

#include "GameObject.h"
#include "AbstractUiElement.h"
#include "Shapes.h"
#include "SdlHelper.h"
#include "SDL_image.h"

#include "SDL.h"
#include <memory>
#include "string"

#undef byte

class Window {
public:
	Window(const char* title, int width, int height);

	SDL_Window* getWindow() const { return _window.get(); }
	SDL_Renderer* getRenderer() const { return _renderer.get(); }

	void update() const;
	void loadImage();


	void cleanUp();
	void clear();
	void render(shared_ptr<GameObject> gameObject);
	//void render(shared_ptr<AbstractUiElement> uiElements);
	//void preRender(shared_ptr<GameObject> gameObjects);
	//void preRender(shared_ptr<AbstractUiElement> uiElements);
	void display();
	//~Window();
private:
	std::string _path;
	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window { nullptr, SDL_DestroyWindow };
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer { nullptr, SDL_DestroyRenderer };
	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> _texture { nullptr, SDL_DestroyTexture };
};

