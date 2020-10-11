#pragma once
#include "AbstractScreen.h"

class PauseScreen : public AbstractScreen
{
public:
	using AbstractScreen::AbstractScreen;
	PauseScreen();
	~PauseScreen();

	void onInit();
	void onTick();
	void onScreenShowed();
	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseClickInput(SDL_MouseButtonEvent e);
};