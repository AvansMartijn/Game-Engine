#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_HudUiElement __declspec(dllexport)
#else
#define GAMEENGINE_HudUiElement __declspec(dllimport)
#endif
// TODO: Standaard UiElements moeten allemaal exposed worden.
#include "AbstractUiElement.h"
#include "AbstractGame.h"

#include <string>
#include <iostream>
using namespace std;

/// <summary>
/// Button element
/// </summary>
class GAMEENGINE_HudUiElement HudUiElement : public AbstractUiElement
{
public:
	using AbstractUiElement::AbstractUiElement;

	HudUiElement(std::string text, Color bgColor, Color fgColor, std::string fontKey, int fontSize);
	~HudUiElement();

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

