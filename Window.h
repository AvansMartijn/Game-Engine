#pragma once

#define byte win_byte_override

#include "GameObject.h"
#include "AbstractUiElement.h"
#include "Shapes.h"
#include "SDL_image.h"

#include "SDL.h"
#include <memory>
#include "string"
#include "AssetRegistry.h"
#include "Rect.h"
#include "Color.h"
#undef byte

class Window {
public:
	Window(const char* title, int width, int height);

	SDL_Window* getWindow() const { return _window.get(); }
	int getWidth() const;
	int getHeight() const;
	void clear();
	void display();

	SDL_Texture* getTexture(std::string filePath);
	TTF_Font* getFont(std::string fontKey, int fontSize);

	void renderRectangle(Rect rect, Color color);
	void renderTexture(std::string textureKey, Rect rect);
	void renderText(std::string text, TTF_Font* font, Rect rect, Color foregroundColor, Color backgroundColor, bool center);

	// TODO: Private + func
	AssetRegistry _assetRegistry;
private:
	int _width;
	int _height;

	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window { nullptr, SDL_DestroyWindow };
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer { nullptr, SDL_DestroyRenderer };
	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> _texture { nullptr, SDL_DestroyTexture };
};

