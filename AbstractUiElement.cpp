#include "AbstractUiElement.h"
AbstractUiElement::AbstractUiElement() {}

AbstractUiElement::~AbstractUiElement() {}

void AbstractUiElement::registerGame(AbstractGame* game) {
	_game = game;
}