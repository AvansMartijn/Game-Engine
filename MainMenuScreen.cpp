#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {}
MainMenuScreen::~MainMenuScreen() {}

void MainMenuScreen::onInit() {
	Color bgColor = { 66, 99, 116 };
	ImageUiElement img = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	uiElements.push_back(make_shared<ImageUiElement>(img));

	TextUiElement text = TextUiElement("  LAPTROP 2   ", "Portal", 48, { 0, 0, 0, 0 }, { 32, 180, 226 }, { 7, 16, 29 }, true);
	uiElements.push_back(make_shared<TextUiElement>(text));

	ButtonUiElement startButton = ButtonUiElement("Start New Game", { (1080 / 2) - 220, 100, 500, 100 }, bgColor, {180, 102, 13 }, "Portal", 40);
	startButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(startButton));

	ButtonUiElement loadButton = ButtonUiElement("Load Game", { (1080 / 2) - 220, 250, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
	loadButton.registerGame(_game);
	uiElements.push_back(make_shared<ButtonUiElement>(loadButton));

	ButtonUiElement creditButton = ButtonUiElement("Credits", { (1080 / 2) - 220, 400, 500, 100 }, bgColor, { 180, 102, 13 }, "Portal", 40);
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
