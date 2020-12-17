#include "pch.h"
#include "AbstractScreen.h"
#include "GameEngine.h"
#include "AbstractGame.h"

AbstractScreen::AbstractScreen() {
	_game = NULL;
}

AbstractScreen::~AbstractScreen() {}

void AbstractScreen::registerGame(AbstractGame* game) {
	_game = game;
}

void AbstractScreen::handleMouseMotionInput(MouseMotionEvent e) {}

void AbstractScreen::handleMouseWheelInput(MouseWheelEvent e) {}

void AbstractScreen::handleMouseClickInput(MouseButtonEvent e) {
	if (e.button == SDL_BUTTON_LEFT) {
		for (unique_ptr<AbstractUiElement>& element : _uiElements) {
			if (element->isInBound(e.x, e.y)) {
				element->onClick(_game);

				break;
			}
		}
	}
}
//void AbstractScreen::handleKeyboardInput(KeyboardEvent e) {}

void AbstractScreen::render(const unique_ptr<Window>& window) {
	for (unique_ptr<AbstractUiElement>& obj : _uiElements)
		obj->render(window);
}

void AbstractScreen::preRender(const unique_ptr<Window>& window) {
	for (unique_ptr<AbstractUiElement>& obj : _uiElements)
		obj->preRender(window);
}

void AbstractScreen::reset() {}

void AbstractScreen::onScreenShowed(vector<std::string> args) {}

void AbstractScreen::addFpsElement(const std::string& fontKey) {
	TextUiElement fps = TextUiElement(" ", fontKey, 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false);
	unique_ptr<TextUiElement> fpsPtr = make_unique<TextUiElement>(fps);
	_fpsElement = addUiElement<TextUiElement>(std::move(fpsPtr));
}

void AbstractScreen::updateFpsElement() {
	if (shouldShowFPS)
		_fpsElement->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fpsElement->text = "  ";
}