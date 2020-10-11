#include "AbstractScreen.h"
AbstractScreen::AbstractScreen() {}

AbstractScreen::~AbstractScreen() {}

void AbstractScreen::registerGame(shared_ptr<AbstractGame> game) {
	_game = game;
}