#include "pch.h"
#include "BehaviourRotate.h"

BehaviourRotate::BehaviourRotate(shared_ptr<GameObject> self, int waitTime) : AbstractBehaviour(self) {
	waitTime = waitTime;
}

void BehaviourRotate::execute() {
	if (isEnoughTimeElapsed(waitTime)) {
		shared_ptr<MoveExtension> moveExtension = _self->getExtension<MoveExtension>();
		moveExtension->isLookingToRight = !moveExtension->isLookingToRight;

		this->executeNextBehaviour(true);
	}
}
