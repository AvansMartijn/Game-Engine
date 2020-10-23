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
public:
	using AbstractUiElement::AbstractUiElement;

	ButtonUiElement(std::string text, Rect rect, Color bgColor, Color fgColor, std::string fontKey, int fontSize);
	~ButtonUiElement();

	/// <summary>
	/// pre render the element
	/// </summary>
	/// <param name="window"></param>
	void preRender(const unique_ptr<Window>& window);
	/// <summary>
	/// Render the element on the screen.
	/// </summary>
	/// <param name="renderer">The renderer</param>
	void render(const unique_ptr<Window>& window);
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
private:
	std::string _text;
	Color _backgroundColor;
	Color _foregroundColor;
	std::string _fontKey;
	int _fontSize;

	// This has to be here, otherwise we have to add every possible fontSize to the registry.
	TTF_Font* _font;
};

