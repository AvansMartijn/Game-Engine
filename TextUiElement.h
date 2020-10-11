#pragma once
#include "AbstractUiElement.h"
#include <string>
#include <iostream>

class TextUiElement: public AbstractUiElement
{
private:
	std::string _text;
	SDL_Color _foregroundColor;
	SDL_Color _backgroundColor;
	int _fontSize;
public:
	TextUiElement(std::string txt, int fontSize, SDL_Rect rect, SDL_Color fgColor, SDL_Color bgColor);
	~TextUiElement();

	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

