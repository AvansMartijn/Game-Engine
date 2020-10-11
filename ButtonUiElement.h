#pragma once
#include "AbstractUiElement.h"
#include "AbstractGame.h"

#include <iostream>
using namespace std;

class ButtonUiElement: public AbstractUiElement
{
private:
	SDL_Color _backgroundColor;
public:
	using AbstractUiElement::AbstractUiElement;

	ButtonUiElement(SDL_Rect rect, SDL_Color bgColor);
	~ButtonUiElement();

	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

