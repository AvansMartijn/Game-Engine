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

shared_ptr<GameObject> AbstractScreen::createEntity(GameEngine gameEngine, vector<string> extensions, std::string textureKey, float x, float y, float width, float height) {
	return createGameObject(gameEngine, extensions, textureKey, x, y, width, height, -1, false, false);
}

shared_ptr<GameObject> AbstractScreen::createGameObject(GameEngine gameEngine, vector<string> extensions, std::string textureKey, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
	shared_ptr<GameObject> gameObject = gameEngine.CreateGameObject(extensions);
	gameObject->textureKey = textureKey;

	if (friction == -1 && !fixed && !fixedRotation)
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
	else
		Physics::getInstance().addBody(gameObject, x, y, width, height, friction, fixed, fixedRotation);

	return gameObject;
}