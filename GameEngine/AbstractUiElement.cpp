#include "pch.h"
#include "AbstractUiElement.h"
AbstractUiElement::AbstractUiElement() {
	_game = NULL;
	rect = {};
	onClick = [](shared_ptr<AbstractGame> game) {std::cout << "No OnClick\n"; };
}

AbstractUiElement::~AbstractUiElement() {}

void AbstractUiElement::registerGame(shared_ptr<AbstractGame> game) {
	_game = game;
}
