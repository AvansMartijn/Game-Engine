#include "pch.h"
#include "BehaviourSeesEnemy.h"

void BehaviourSeesEnemy::execute() {
	std::cout << "> Look\n";

	this->executeNextBehaviour(true);
}
