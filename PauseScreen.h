#pragma once
#include "AbstractScreen.h"

class PauseScreen : public AbstractScreen
{
public:
	using AbstractScreen::AbstractScreen;

	void init();
	void tick();
	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseClickInput(SDL_MouseButtonEvent e);
};