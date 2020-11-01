#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_WINDOW __declspec(dllexport)
#else
#define GAMEENGINE_WINDOW __declspec(dllimport)
#endif

#define byte win_byte_override

#include "GameObject.h"
#include "AbstractUiElement.h"
#include <memory>
#include "string"
#include "AssetRegistry.h"
#include "Rect.h"
#include "Color.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#undef byte

class GAMEENGINE_WINDOW Window {
public:
	Window(const char* title, int width, int height);

	SDL_Window* getWindow() const { return _window.get(); }
	int getWidth() const;
	int getHeight() const;
	void clear();
	void display();

	void registerTexture(std::string textureKey, std::string texturePath);
	void registerFont(std::string fontKey, std::string fontPath);

	SDL_Texture* getTexture(std::string filePath) const;
	TTF_Font* getFont(std::string fontKey, int fontSize);

	void renderRectangle(Rect rect, Color color);
	void renderTexture(std::string textureKey, Rect rect, float angle = 0, bool flipRight = true);
	void renderText(std::string text, TTF_Font* font, Rect rect, Color foregroundColor, Color backgroundColor, bool center);
private:
	int _width;
	int _height;
	AssetRegistry _assetRegistry;

	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window{ nullptr, SDL_DestroyWindow };
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer{ nullptr, SDL_DestroyRenderer };
	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> _texture{ nullptr, SDL_DestroyTexture };
};

