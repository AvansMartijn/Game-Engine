#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {}
MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::onInit() {
	Color bgColor = { 192, 192, 192 };

	TextUiElement text = TextUiElement("Laptrop 2", "OpenSans", 48, { 0, 0, 0, 0 }, { 0, 0, 0 }, { 255, 255, 255 }, true);
	uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement startButton = ButtonUiElement("Start New Game", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 0, 0, 0 }, "OpenSans", 32);
	startButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(startButton));

	ButtonUiElement loadButton = ButtonUiElement("Load Game", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 0, 0, 0 }, "OpenSans", 32);
	loadButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(loadButton));

	ButtonUiElement creditButton = ButtonUiElement("Credits", { (1080 / 2) - 200, 100, 500, 100 }, bgColor, { 0, 0, 0 }, "OpenSans", 32);
	creditButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(creditButton));
}

void MainMenuScreen::onTick() {

}

void MainMenuScreen::onScreenShowed() {

}

void MainMenuScreen::handleKeyboardInput(SDL_KeyboardEvent e) {

}

void MainMenuScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void MainMenuScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (auto& element : uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick();

				break;
			}
		}
	}
}
