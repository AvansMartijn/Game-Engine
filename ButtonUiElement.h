#pragma once
#include "AbstractUiElement.h"
#include "AbstractGame.h"
#include "TextUiElement.h"

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
public:
	using AbstractUiElement::AbstractUiElement;

	ButtonUiElement(std::string text, SDL_Rect rect, SDL_Color bgColor, SDL_Color fgColor);
	~ButtonUiElement();

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

