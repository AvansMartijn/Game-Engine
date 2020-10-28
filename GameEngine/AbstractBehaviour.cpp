#include "pch.h"
#include "AbstractBehaviour.h"
AbstractBehaviour::AbstractBehaviour(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene) {
	this->_self = self;
	this->_scene = scene;
}

void AbstractBehaviour::executeNextBehaviour(bool isTrue) {
	if (isTrue && this->behaviourTrue)
		this->behaviourTrue->execute();
	else if (!isTrue && this->behaviourFalse)
		this->behaviourFalse->execute();
}
