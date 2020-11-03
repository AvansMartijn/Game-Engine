#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_TextUiElement __declspec(dllexport)
#else
#define GAMEENGINE_TextUiElement __declspec(dllimport)
#endif
// TODO: Standaard UiElements moeten allemaal exposed worden.
#include "AbstractUiElement.h"
#include "Color.h"

#include <string>
#include <iostream>

class GAMEENGINE_TextUiElement TextUiElement : public AbstractUiElement
{
public:
	TextUiElement(std::string txt, std::string fontKey, int fontSize, Rect rect, Color fgColor, Color bgColor, bool center);
	~TextUiElement();
	std::string text;

	/// <summary>
	/// prerender
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
	std::string _fontKey;
	int _fontSize;
	Color _foregroundColor;
	Color _backgroundColor;
	bool _center;

	// This has to be here, otherwise we have to add every possible fontSize to the registry.
	TTF_Font* _font;
};

