#include "WorkshopUiScreen.h"
#include <ButtonUiElement.h>

WorkshopUiScreen::WorkshopUiScreen() {}
WorkshopUiScreen::~WorkshopUiScreen() {}

void WorkshopUiScreen::onInit() {
	// Create UI Elements
	ButtonUiElement startButton = ButtonUiElement("New Game", { 0, 0, 200, 40 }, { 28, 28, 28 }, { 255, 255, 255 }, "OpenSans", 25);
	startButton.registerGame(_game);
	startButton.onClick = [](AbstractGame* game) {
		game->switchScreen(1);
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(startButton));
}

void WorkshopUiScreen::onTick() {

}

void WorkshopUiScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
}

void WorkshopUiScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void WorkshopUiScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

}