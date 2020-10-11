#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

class AbstractGame;
class AbstractUiElement
{
protected:
	AbstractGame* _game;
	SDL_Rect _rectangle;
public:
	AbstractUiElement();
	~AbstractUiElement();

	virtual void preRender(SDL_Renderer* renderer) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual void onClick() = 0;
	virtual bool isInBound(int mouseX, int mouseY) = 0;
	virtual void registerGame(AbstractGame* game);
};

