#include "pch.h"
#include "AbstractScreen.h"
#include "GameEngine.h"

AbstractScreen::AbstractScreen() {
	_game = NULL;
}

AbstractScreen::~AbstractScreen() {}

void AbstractScreen::registerGame(shared_ptr<AbstractGame> game) {
	_game = game;
}

void AbstractScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (shared_ptr<AbstractUiElement>& element : _uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick(_game);

				break;
			}
		}
	}
}


void AbstractScreen::render(const unique_ptr<Window>& window) {
	for (shared_ptr<AbstractUiElement>& obj : _uiElements)
		obj->render(window);
}

void AbstractScreen::preRender(const unique_ptr<Window>& window) {
	for (shared_ptr<AbstractUiElement>& obj : _uiElements)
		obj->preRender(window);
}

void AbstractScreen::reset() {}

void AbstractScreen::onScreenShowed(vector<std::string> args) {}