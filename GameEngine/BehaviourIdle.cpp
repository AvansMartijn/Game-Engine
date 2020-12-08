#include "pch.h"
#include "BehaviourIdle.h"
#include <thread>
void BehaviourIdle::execute() {
	this->executeNextBehaviour(true);
}
