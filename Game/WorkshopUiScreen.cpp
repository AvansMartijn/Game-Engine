#include "WorkshopUiScreen.h"
#include <ButtonUiElement.h>
#include <TextUiElement.h>

WorkshopUiScreen::WorkshopUiScreen() {}
WorkshopUiScreen::~WorkshopUiScreen() {}

void WorkshopUiScreen::onInit() {	
	// Create UI Elements
	TextUiElement headerText = TextUiElement("Our Workshop", "OpenSans", 25, { 100, 0, 200, 40 }, { 28, 28, 28 }, { 255, 255, 255 }, false, false);
	headerText.registerGame(_game);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	ButtonUiElement startButton = ButtonUiElement("New Game", { 100, 100, 200, 40 }, { 28, 28, 28 }, { 255, 255, 255 }, "OpenSans", 25);
	startButton.registerGame(_game);
	startButton.onClick = [](AbstractGame* game) {
		game->switchScreen(1);
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(startButton));

	// TODO: Add Custom UI Element

}

void WorkshopUiScreen::onTick() {

}

void WorkshopUiScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
}

void WorkshopUiScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void WorkshopUiScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

}