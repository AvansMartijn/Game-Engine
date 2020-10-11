#pragma once
#include "AbstractUiElement.h"
#include "SdlHelper.h"

#include <string>
#include <iostream>

class TextUiElement: public AbstractUiElement
{
private:
	std::string _text;
	SDL_Color _foregroundColor;
	SDL_Color _backgroundColor;
	int _fontSize;
	bool _center;
	TTF_Font* _font;
	SdlHelper _sdlHelper;
public:
	TextUiElement(std::string txt, int fontSize, SDL_Rect rect, SDL_Color fgColor, SDL_Color bgColor, bool center);
	~TextUiElement();

	void preRender(SDL_Renderer* renderer);
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void render(SDL_Renderer* renderer);
	/// <summary>
	/// The function executed when the element is clicked on.
	/// </summary>
	void onClick();
	/// <summary>
	/// Checks if the mouse is within the bounds of the element.
	/// </summary>
	/// <param name="mouseX">X coordinate of the mouse</param>
	/// <param name="mouseY">Y coordinate of the mouse</param>
	/// <returns></returns>
	bool isInBound(int mouseX, int mouseY);
};

