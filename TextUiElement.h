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
	bool _center;
public:
	TextUiElement(std::string txt, int fontSize, SDL_Rect rect, SDL_Color fgColor, SDL_Color bgColor, bool center);
	~TextUiElement();

	void preRender(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

