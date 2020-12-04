#pragma once
#include "AbstractScreen.h"

class WorkshopUiScreen : public AbstractScreen {
public:
	WorkshopUiScreen();
	~WorkshopUiScreen();

	void onInit();
	void onTick();

	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
};