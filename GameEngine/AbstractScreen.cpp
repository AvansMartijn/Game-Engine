#include "pch.h"
#include "AbstractScreen.h"
AbstractScreen::AbstractScreen() {
	_game = NULL;
}

AbstractScreen::~AbstractScreen() {}

void AbstractScreen::registerGame(AbstractGame* game) {
	_game = game;
}
