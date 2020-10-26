#include "pch.h"
#include "BehaviourRotate.h"

void BehaviourRotate::execute() {
	std::cout << "> Rotate\n";

	this->executeNextBehaviour(true);
}

bool BehaviourRotate::hasEnoughTimeElapsed() {
	return false;
}

bool BehaviourRotate::canRotate() {
	return false;
}
