#include "AbstractScreen.h"
AbstractScreen::AbstractScreen() {}

AbstractScreen::~AbstractScreen() {}

void AbstractScreen::registerGame(AbstractGame* game) {
	_game = game;
}