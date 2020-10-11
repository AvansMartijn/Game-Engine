#pragma once
#include <memory>
#include <vector>
#include "Window.h"
#include "AbstractUiElement.h"
using namespace std;

class AbstractGame;
class AbstractScreen
{
protected:
	shared_ptr<AbstractGame> _game;
public:
	AbstractScreen();
	~AbstractScreen();
	
	vector<shared_ptr<GameObject>> gameObjects;
	vector<shared_ptr<AbstractUiElement>> uiElements;

	virtual void init() = 0;
	virtual void tick() = 0;
	virtual void handleKeyboardInput(SDL_KeyboardEvent e) = 0;
	virtual void handleMouseMotionInput(SDL_MouseMotionEvent e) = 0;
	virtual void handleMouseClickInput(SDL_MouseButtonEvent e) = 0;
	virtual void registerGame(shared_ptr<AbstractGame> game);
};

