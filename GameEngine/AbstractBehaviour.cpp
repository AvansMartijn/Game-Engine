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

bool AbstractBehaviour::isEnoughTimeElapsed(int timeNeeded) {
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	long diff  = std::chrono::duration_cast<std::chrono::milliseconds>(end - _begin).count();

	if (diff >= timeNeeded)
		_begin = std::chrono::steady_clock::now();

	return diff >= timeNeeded;
}
