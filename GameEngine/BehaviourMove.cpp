#include "pch.h"
#include "BehaviourMove.h"

void BehaviourMove::execute() {
	shared_ptr<MoveExtension> extension = _self->getExtension<MoveExtension>();

	if (_self->body.b2body->GetLinearVelocity().y == 0) {
		extension->move(extension->isLookingToRight ? 2 : -2, 0);

		// TODO: Look if player collides with entity. (yes = false, no = true)
		this->executeNextBehaviour(true);
	}
}
