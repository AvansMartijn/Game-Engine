#include "pch.h"
#include "AbstractScreen.h"
#include "GameEngine.h"

AbstractScreen::AbstractScreen() {
	_game = NULL;
}

AbstractScreen::~AbstractScreen() {}

void AbstractScreen::registerGame(AbstractGame* game) {
	_game = game;
}

void AbstractScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (shared_ptr<AbstractUiElement>& element : uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick(_game);

				break;
			}
		}
	}
}