#include "pch.h"
#include "AbstractEntityAI.h"
AbstractEntityAI::AbstractEntityAI() {}

void AbstractEntityAI::execute() {
	if (_currentBehaviour->isEnoughTimeElapsed(100))
		_currentBehaviour->execute();
}