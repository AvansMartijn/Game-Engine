#include "pch.h"
#include "BehaviourAttack.h"

void BehaviourAttack::execute() {
	std::cout << "> Attack\n";

	this->executeNextBehaviour(true);
}

bool BehaviourAttack::canAttack() {
	return false;
}
