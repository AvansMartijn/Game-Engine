#include "pch.h"
#include "BehaviourRotate.h"
#include "Utilities.h"

BehaviourRotate::BehaviourRotate(shared_ptr<GameObject> self, int waitTime) : AbstractBehaviour(self) {
	_waitTime = waitTime;
}

void BehaviourRotate::execute() {
	if (Utilities::getInstance().isEnoughTimeElapsed(_waitTime, _begin)) {
		shared_ptr<MoveExtension> moveExtension = _self->getExtension<MoveExtension>();
		moveExtension->isLookingToLeft = !moveExtension->isLookingToLeft;

		this->executeNextBehaviour(true);
	}
}
