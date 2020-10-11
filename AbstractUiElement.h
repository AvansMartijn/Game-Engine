#pragma once
#include "SDL.h"

class AbstractUiElement
{
public:
	AbstractUiElement();
	~AbstractUiElement();
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual void onClick() = 0;
	virtual bool isInBound(int mouseX, int mouseY) = 0;
};

