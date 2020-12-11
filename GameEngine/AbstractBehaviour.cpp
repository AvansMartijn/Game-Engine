#include "pch.h"
#include "AbstractBehaviour.h"
AbstractBehaviour::AbstractBehaviour(shared_ptr<GameObject> self) {
	_self = self;
	_begin = std::chrono::steady_clock::now();
}

void AbstractBehaviour::executeNextBehaviour(bool isTrue) {
	if (isTrue && this->behaviourTrue)
		this->behaviourTrue->execute();
	else if (!isTrue && this->behaviourFalse)
		this->behaviourFalse->execute();
}
