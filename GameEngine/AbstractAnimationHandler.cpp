#include "pch.h"
#include "AbstractAnimationHandler.h"

std::string AbstractAnimationHandler::getKeyFromMovementType(MovementType movementType) {
	std::string key = KEY_IDLE;
	switch (movementType)
	{
	case MovementType::IDLE:
		key = KEY_IDLE;
		break;
	case MovementType::RUNNING:
		key = KEY_RUNNING;
		break;
	case MovementType::JUMPING:
		key = KEY_JUMPING;
		break;
	case MovementType::ATTACKING:
		key = KEY_ATTACKING;
		break;
	case MovementType::AFK:
		key = KEY_AFK;
		break;
	case MovementType::HURTING:
		key = KEY_HURTING;
		break;
	default:
		break;
	}

	return key;
}