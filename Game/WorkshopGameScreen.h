#pragma once
#include <ButtonUiElement.h>

class WorkshopGameScreen : public AbstractScreen {
public:
	WorkshopGameScreen();
	~WorkshopGameScreen();

	void onInit();
	void onTick();

	void handleKeyboardInput(SDL_KeyboardEvent e);
	void handleMouseMotionInput(SDL_MouseMotionEvent e);
	void handleMouseWheelInput(SDL_MouseWheelEvent e);
};

