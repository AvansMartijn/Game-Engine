#include "PlayerAnimationHandler.h"
#include "GameObject.h"

void PlayerAnimationHandler::registerAnimations() {
	//_animations
	_currentFrame = 0;
	_currentCooldown = 1000;

	std::vector<Rect> frames;

	// Idle
	frames.push_back(Rect{ 253, 78, 318, 456 });
	frames.push_back(Rect{ 1877, 72, 324, 462 });
	_animations.insert(make_pair(KEY_IDLE, frames));

	// Running
	frames.clear();
	frames.push_back(Rect{ 44, 735, 448, 448 });
	//frames.push_back(Rect{ 1032, 735, 481, 445 });
	_animations.insert(make_pair(KEY_RUNNING, frames));

	// Jumping
	frames.clear();
	frames.push_back(Rect{ 2058, 654, 385, 519 });
	_animations.insert(make_pair(KEY_JUMPING, frames));
}

void PlayerAnimationHandler::animate(std::shared_ptr<GameObject> gameObject) {
	if (gameObject->hasExtension(typeid(MoveExtension))) {
		shared_ptr<MoveExtension> moveExtension = gameObject->getExtension<MoveExtension>();
		shouldFlipRight = moveExtension->isLookingToRight;

		if (getKeyFromMovementType(moveExtension->currentMovementType) != currentAnimation) {
			_currentFrame = 0;
			// TODO: Switch animation
			
			Vec2 velocity = Physics::getInstance().getLinearVelocity(gameObject);
		
			if (moveExtension->currentMovementType == MovementType::RUNNING) {
				currentAnimation = KEY_RUNNING;
				_currentCooldown = 200;
			}
			else if (moveExtension->currentMovementType == MovementType::JUMPING) {
				currentAnimation = KEY_JUMPING;
				_currentCooldown = 0;
			}
			else if (moveExtension->currentMovementType == MovementType::IDLE || (moveExtension->currentMovementType == MovementType::RUNNING && velocity.x == 0)) {
				currentAnimation = KEY_IDLE;
				_currentCooldown = 1000;
			}
		}
		else if (isEnoughTimeElapsed(_currentCooldown)) {
			_currentFrame++;

			if (_currentFrame == _animations[currentAnimation].size())
				_currentFrame = 0;
		}

		std::vector<Rect> frames = _animations[currentAnimation];
		sprite = frames[_currentFrame];
	}
}

std::string PlayerAnimationHandler::getKeyFromMovementType(MovementType movementType) {
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
	default:
		break;
	}

	return key;
}