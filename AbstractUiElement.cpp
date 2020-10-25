#include "AbstractUiElement.h"
AbstractUiElement::AbstractUiElement() {
	_game = NULL;
	_rect = {};
}

AbstractUiElement::~AbstractUiElement() {}

void AbstractUiElement::registerGame(AbstractGame* game) {
	_game = game;
}