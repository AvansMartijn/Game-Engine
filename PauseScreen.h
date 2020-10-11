#pragma once
#include "AbstractScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
#include "TextUiElement.h"
#include "ImageUiElement.h"

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