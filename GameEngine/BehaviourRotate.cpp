#include "pch.h"
#include "BehaviourRotate.h"

void BehaviourRotate::execute() {
	std::cout << "> Rotate\n";
	shared_ptr<EntityMovementExtension> movementExtension = _self->getExtension<EntityMovementExtension>();
	movementExtension->isLookingRight = !movementExtension->isLookingRight;

	this->executeNextBehaviour(true);
}
