#pragma once
#include "AbstractUiElement.h"
#include "AbstractGame.h"

#include <string>
#include <iostream>
using namespace std;

/// <summary>
/// Button element
/// </summary>
class ButtonUiElement: public AbstractUiElement
{
private:
	string _text;
	SDL_Color _backgroundColor;
	SDL_Color _foregroundColor;
	TTF_Font* _font;
	int _fontSize;
	SdlHelper _sdlHelper;
public:
	using AbstractUiElement::AbstractUiElement;

	ButtonUiElement(std::string text, SDL_Rect rect, SDL_Color bgColor, SDL_Color fgColor, int fontSize);
	~ButtonUiElement();

	/// This is called one time before going into the render loop.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void preRender(Window* window);
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void render(Window* window);
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

