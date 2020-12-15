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
private:
	int _width;
	int _height;

	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window{ nullptr, SDL_DestroyWindow };
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer{ nullptr, SDL_DestroyRenderer };
public:
	Window(const char* title, int width, int height);

	// TODO: WEG WERKEN.
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
	/// <param name="isReversed">If the texture should be reversed.</param>
	void registerTexture(const std::string& textureKey, const std::string& texturePath, bool isReversed = false);

	/// <summary>
	/// Adds all textures within a directory to the registry.
	/// </summary>
	/// <param name="prefix">The prefix we want to use for these textures.</param>
	/// <param name="directory">The directory which we want to add.</param>
	/// <param name="isDeep">If we should scan the directories within this directory.</param>
	void registerTextures(const std::string& prefix, const std::string& directory, bool isDeep);

	/// <summary>
	/// Registers the font in the asset registry.
	/// </summary>
	/// <param name="fontKey">The font key.</param>
	/// <param name="fontPath">The path to the font.</param>
	void registerFont(const std::string& fontKey, const std::string& fontPath);

	// TODO: WEG WERKEN.
	/// <summary>
	/// Get's the font from the given path.
	/// </summary>
	/// <param name="fontKey">The font key</param>
	/// <param name="fontSize">The size of the font.</param>
	/// <returns>The font.</returns>
	TTF_Font* getFont(const std::string& fontKey, int fontSize);
	
	/// <summary>
	/// Renders a rectangle on the screen.
	/// </summary>
	/// <param name="rect">The rectangle we want to draw.</param>
	/// <param name="color">The color we want to fill the rectangle with.</param>
	void renderRectangle(const Rect& rect, const Color& color);

	/// <summary>
	/// Renders a texture on the screen.
	/// </summary>
	/// <param name="textureKey">The texture key.</param>
	/// <param name="rect">The rectangle.</param>
	/// <param name="angle">The angle.</param>
	/// <param name="flipRight">If we need to flip left.</param>
	/// <param name="alpha">The alpha of the texture.</param>
	void renderTexture(const std::string& textureKey, const Rect& rect, float angle = 0, bool flipLeft = true, int alpha = 0);
	
	/// <summary>
	/// Renders a sprite on the screen
	/// </summary>
	/// <param name="textureKey">The texture key.</param>
	/// <param name="rect">The render rect.</param>
	/// <param name="sprite">The sprite rect.</param>
	/// <param name="angle">The angle.</param>
	/// <param name="flipRight">If we need to flip left.</param>
	void renderSprite(const std::string& textureKey, const Rect& rect, const Rect& sprite, float angle = 0, bool flipLeft = false);

	/// <summary>
	/// Renders text on the screen.
	/// </summary>
	/// <param name="text">The text we want to render.</param>
	/// <param name="font">The font we want to use.</param>
	/// <param name="rect">The rectangle.</param>
	/// <param name="foregroundColor">The foreground color.</param>
	/// <param name="backgroundColor">The background color.</param>
	/// <param name="center">If we want to center the text.</param>
	void renderText(const std::string& text, TTF_Font* font, const Rect& rect, const Color& foregroundColor, const Color& backgroundColor, bool center, bool multiLine = false);

	/// <summary>
	/// Render a multi line text area.
	/// </summary>
	/// <param name="text">The text we want to render.</param>
	/// <param name="font">The font we want to use.</param>
	/// <param name="rect">The rectangle.</param>
	/// <param name="foregroundColor">The foreground color.</param>
	/// <param name="backgroundColor">The background color.</param>
	/// <param name="center">If we want to center the text.</param>
	/// <param name="multiLine">If we should render multiple lines.</param>
	void renderMultiLineText(std::vector<std::string> text, TTF_Font* font, const Rect& rect, const Color& foregroundColor, const Color& backgroundColor, bool center, bool multiLine = false);

	/// <summary>
	/// Render a hp bar
	/// </summary>
	/// <param name="x">x pos</param>
	/// <param name="y">y pos</param>
	/// <param name="w">width</param>
	/// <param name="h">height</param>
	/// <param name="percent">Precent to fill the bar</param>
	/// <param name="fgColor">Front color</param>
	/// <param name="bgColor">Background color</param>
	void renderHPBar(int x, int y, int w, int h, float percent, const Color& fgColor, const Color& bgColor);

	/// <summary>
	/// Converts pixels to meters.
	/// </summary>
	/// <param name="value">The value in pixels.</param>
	/// <returns>The value in meters.</returns>
	int metersToPixels(float value);
};

