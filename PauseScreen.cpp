#include "PauseScreen.h"
#include <iostream>
#include "AbstractGame.h"
#include "ButtonUiElement.h"
using namespace std;

void PauseScreen::init() {
	cout << "PAUSE\n";

	ButtonUiElement button = ButtonUiElement{};
	button.x = 0;
	button.y = 0;
	button.width = 100;
	button.height = 100;

	uiElements.push_back(make_shared<ButtonUiElement>(button));
}

void PauseScreen::tick() {

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
