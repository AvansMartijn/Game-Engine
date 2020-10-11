#pragma once
#include "AbstractScreen.h"
#include "GameObject.h"
#include "Window.h"

class GameScreen: public AbstractScreen
{
private:
	shared_ptr<GameObject> _player;
public:
	using AbstractScreen::AbstractScreen;
	GameScreen();
	void init();
	void tick();
	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseClickInput(SDL_MouseButtonEvent e);
};

