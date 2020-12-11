#pragma once
#include "AbstractAnimationHandler.h"
#include "MovementType.h"
#include "Physics.h"

class PlayerAnimationHandler : public AbstractAnimationHandler {
public:
	void registerAnimations();
	void animate(std::shared_ptr<GameObject> gameObject);
};

