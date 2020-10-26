#include "AbstractUiElement.h"
AbstractUiElement::AbstractUiElement() {
	_game = NULL;
	_rect = {};

	onClick = [](AbstractGame* game) {std::cout << "No OnClick\n"; };
}

AbstractUiElement::~AbstractUiElement() {}

void AbstractUiElement::registerGame(AbstractGame* game) {
	_game = game;
}