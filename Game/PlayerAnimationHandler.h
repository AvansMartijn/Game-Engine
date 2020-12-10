#pragma once
#include "AbstractAnimationHandler.h"
#include "MovementType.h"
#include "Physics.h"

class PlayerAnimationHandler : public AbstractAnimationHandler {
public:
	const std::string KEY_IDLE = "IDLE";
	const std::string KEY_RUNNING = "RUNNING";
	const std::string KEY_JUMPING = "JUMPING";

	void registerAnimations();
	void animate(std::shared_ptr<GameObject> gameObject);
	std::string getKeyFromMovementType(MovementType movementType);
};

