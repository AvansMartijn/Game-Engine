#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_TextUiElement __declspec(dllexport)
#else
#define GAMEENGINE_TextUiElement __declspec(dllimport)
#endif
#include "AbstractUiElement.h"
#include "Color.h"

#include <string>
#include <iostream>

class GAMEENGINE_TextUiElement TextUiElement : public AbstractUiElement {
private:
	std::string _fontKey;
	int _fontSize;
	Color _foregroundColor;
	Color _backgroundColor;
	bool _center;
	bool _multiLine;

	// This has to be here, otherwise we have to add every possible fontSize to the registry.
	TTF_Font* _font;
public:
	//TextUiElement() {}
	TextUiElement(const std::string& txt, const std::string& fontKey, int fontSize, const Rect& textRect, const Color& fgColor, const Color& bgColor, bool center, bool mutliLine = false);
	TextUiElement(std::vector<std::string> txt, const std::string& fontKey, int fontSize, const Rect& rect, const Color& fgColor, const Color& bgColor, bool center, bool mutliLine = false);
	~TextUiElement();

	std::string text;
	std::vector<std::string> textLines;

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
	bool isInBound(int mouseX, int mouseY) const;
};

