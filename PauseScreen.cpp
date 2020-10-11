#include "PauseScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
#include "TextUiElement.h"
#include "ImageUiElement.h"

PauseScreen::PauseScreen() {}
PauseScreen::~PauseScreen() {}

void PauseScreen::onInit() {
	cout << "PAUSE\n";

	SDL_Rect rect = { 0, 0, 100, 100 };
	SDL_Color bgColor = { 255, 0, 0, 255 };
	ButtonUiElement button = ButtonUiElement(rect, bgColor);
	button.registerGame(_game);

	uiElements.push_back(make_shared<ButtonUiElement>(button));

	TextUiElement text = TextUiElement("Hello World", 12, { 200, 0, 100, 100 }, { 255, 0, 0 }, { 255, 255, 255 });
	uiElements.push_back(make_shared<TextUiElement>(text));

	ImageUiElement img = ImageUiElement("res/gfx/KINGKROOL.png", { 200, 200, 100, 100 });
	uiElements.push_back(make_shared<ImageUiElement>(img));
}

void PauseScreen::onTick() {

}

void PauseScreen::onScreenShowed() {

}

void PauseScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		cout << "ESCAPE\n";
		_game->switchScreen(0);

		break;
	default:
		break;
	}
}

void PauseScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void PauseScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (auto& element : uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick();

				break;
			}
		}
	}
}
