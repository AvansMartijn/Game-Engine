#include "BehaviourMove.h"

void BehaviourMove::execute() {
	std::cout << "> Move\n";

	this->executeNextBehaviour(true);
}

bool BehaviourMove::isMovable() {
	return false;
}

bool BehaviourMove::isWallHit() {
	return false;
}