#include "pch.h"
#include "AbstractEntityAI.h"
AbstractEntityAI::AbstractEntityAI() {}

void AbstractEntityAI::execute() {
	_currentBehaviour->isEnoughTimeElapsed(1000);
	_currentBehaviour->execute();
}