#pragma once
#include "AbstractUiElement.h"

class ButtonUiElement: public AbstractUiElement
{
public:
	using AbstractUiElement::AbstractUiElement;

	ButtonUiElement();
	~ButtonUiElement();

	int x;
	int y;
	int width;
	int height;

	void render(SDL_Renderer* renderer);
	void onClick();
	bool isInBound(int mouseX, int mouseY);
};

