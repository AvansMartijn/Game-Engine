#pragma once
#include "AbstractUiElement.h"
#include "AbstractGame.h"
#include "TextUiElement.h"

#include <string>
#include <iostream>
using namespace std;

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
	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

