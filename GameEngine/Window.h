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

	/// <summary>
	/// Get's the window pointer.
	/// </summary>
	/// <returns>The window pointer.</returns>
	SDL_Window* getWindow() const { return _window.get(); }

	/// <summary>
	/// Get's the width 
	/// </summary>
	/// <returns>The width.</returns>
	int getWidth() const;

	/// <summary>
	/// Get's the height.
	/// </summary>
	/// <returns>The height.</returns>
	int getHeight() const;

	/// <summary>
	/// Clears the window.
	/// </summary>
	void clear();

	/// <summary>
	/// Renders the screen.
	/// </summary>
	void display();

	/// <summary>
	/// Register the texture in the asset registry.
	/// </summary>
	/// <param name="textureKey">The texture key./param>
	/// <param name="texturePath">The path to the texture.</param>
	void registerTexture(std::string textureKey, std::string texturePath);

	/// <summary>
	/// Adds all textures within a directory to the registry.
	/// </summary>
	/// <param name="prefix">The prefix we want to use for these textures.</param>
	/// <param name="directory">The directory which we want to add.</param>
	/// <param name="isDeep">If we should scan the directories within this directory.</param>
	void registerTextures(std::string prefix, std::string directory, bool isDeep);

	/// <summary>
	/// Registers the font in the asset registry.
	/// </summary>
	/// <param name="fontKey">The font key.</param>
	/// <param name="fontPath">The path to the font.</param>
	void registerFont(std::string fontKey, std::string fontPath);

	/// <summary>
	/// Get's the texture from the given path.
	/// </summary>
	/// <param name="filePath">The path to the texture</param>
	/// <returns>The texture.</returns>
	SDL_Texture* getTexture(std::string filePath) const;

	/// <summary>
	/// Get's the font from the given path.
	/// </summary>
	/// <param name="fontKey">The font key</param>
	/// <param name="fontSize">The size of the font.</param>
	/// <returns>The font.</returns>
	TTF_Font* getFont(std::string fontKey, int fontSize);
	
	/// <summary>
	/// Renders a rectangle on the screen.
	/// </summary>
	/// <param name="rect">The rectangle we want to draw.</param>
	/// <param name="color">The color we want to fill the rectangle with.</param>
	void renderRectangle(Rect rect, Color color);

	/// <summary>
	/// Renders a texture on the screen.
	/// </summary>
	/// <param name="textureKey">The texture key.</param>
	/// <param name="rect">The rectangle.</param>
	/// <param name="angle">The angle.</param>
	/// <param name="flipRight">If we need to flip right.</param>
	void renderTexture(std::string textureKey, Rect rect, float angle = 0, bool flipRight = true);
	
	/// <summary>
	/// Renders text on the screen.
	/// </summary>
	/// <param name="text">The text we want to render.</param>
	/// <param name="font">The font we want to use.</param>
	/// <param name="rect">The rectangle.</param>
	/// <param name="foregroundColor">The foreground color.</param>
	/// <param name="backgroundColor">The background color.</param>
	/// <param name="center">If we want to center the text.</param>
	void renderText(std::string text, TTF_Font* font, Rect rect, Color foregroundColor, Color backgroundColor, bool center, int wrapAtPixel = 0);
private:
	int _width;
	int _height;

	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window{ nullptr, SDL_DestroyWindow };
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer{ nullptr, SDL_DestroyRenderer };
	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> _texture{ nullptr, SDL_DestroyTexture };
};

