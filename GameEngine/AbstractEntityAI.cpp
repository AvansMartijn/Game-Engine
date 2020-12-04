#include "pch.h"
#include "AbstractEntityAI.h"
AbstractEntityAI::AbstractEntityAI() {}

void AbstractEntityAI::execute() {
	// More to come here.
	if (_currentBehaviour->isEnoughTimeElapsed(1000)) {
		_currentBehaviour->execute();
	}
}