#include "pch.h"
#include "AbstractEntityAI.h"
#include "Utilities.h"

AbstractEntityAI::AbstractEntityAI() {}

void AbstractEntityAI::execute() {
	if (Utilities::getInstance().isEnoughTimeElapsed(100, _begin))
		_currentBehaviour->execute();
}