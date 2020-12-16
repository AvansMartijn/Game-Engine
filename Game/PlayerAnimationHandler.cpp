#include "PlayerAnimationHandler.h"
#include "GameObject.h"
#include <Utilities.h>

void PlayerAnimationHandler::registerAnimations() {
	//_animations
	_currentFrame = 0;
	_currentCooldown = 1000;

	std::vector<Rect> frames;

	// IDLE
	frames.push_back(Rect{ 101, 6, 25, 45 });
	_animations.insert(make_pair(KEY_IDLE, frames));

	// AFK
	frames.clear();
	frames.push_back(Rect{ 101, 6, 25, 45 });
	frames.push_back(Rect{ 328, 926, 24, 47 });
	frames.push_back(Rect{ 363, 920, 23, 53 });
	frames.push_back(Rect{ 393, 923, 31, 50 });
	frames.push_back(Rect{ 435, 918, 32, 55 });
	frames.push_back(Rect{ 471, 919, 27, 54 });
	frames.push_back(Rect{ 501, 919, 23, 54 });
	frames.push_back(Rect{ 527, 919, 27, 54 });
	frames.push_back(Rect{ 558, 919, 23, 54 });
	frames.push_back(Rect{ 592, 917, 36, 56 });
	frames.push_back(Rect{ 638, 921, 41, 48 });
	frames.push_back(Rect{ 688, 920, 26, 49 });
	frames.push_back(Rect{ 730, 918, 35, 51 });
	frames.push_back(Rect{ 772, 919, 32, 50 });
	frames.push_back(Rect{ 101, 6, 25, 45 });

	_animations.insert(make_pair(KEY_AFK, frames));

	// Running
	frames.clear();
	frames.push_back(Rect{ 288, 13, 35, 46 });
	frames.push_back(Rect{ 326, 15, 35, 47 });
	frames.push_back(Rect{ 363, 16, 36, 43 });
	frames.push_back(Rect{ 421, 14, 35, 47 });
	frames.push_back(Rect{ 471, 16, 33, 46 });
	frames.push_back(Rect{ 510, 17, 39, 44 });

	_animations.insert(make_pair(KEY_RUNNING, frames));

	// Jumping
	frames.clear();
	frames.push_back(Rect{ 67, 198, 40, 47 });

	_animations.insert(make_pair(KEY_JUMPING, frames));

	// Hurting
	frames.clear();
	frames.push_back(Rect{ 189, 923, 33, 42 });
	frames.push_back(Rect{ 228, 925, 33, 41 });
	_animations.insert(make_pair(KEY_HURTING, frames));
}

void PlayerAnimationHandler::animate(std::shared_ptr<GameObject> gameObject) {
	if (gameObject->hasExtension(typeid(MoveExtension))) {
		MoveExtension* moveExtension = gameObject->getExtension<MoveExtension>();
		shouldFlipLeft = moveExtension->isLookingToLeft;

		std::string movementType = getKeyFromMovementType(moveExtension->currentMovementType);
		if (movementType != currentAnimation) {
			_currentFrame = 0;

			Vec2 velocity = Physics::getInstance().getLinearVelocity(gameObject);

			currentAnimation = movementType;
			if (movementType == KEY_RUNNING)
				_currentCooldown = 200;
			else if (movementType == KEY_JUMPING)
				_currentCooldown = 0;
			else if (movementType == KEY_IDLE)
				_currentCooldown = 200;
			else if (movementType == KEY_AFK)
				_currentCooldown = 200;
			else if (movementType == KEY_HURTING)
				_currentCooldown = 200;
		}
		else if (Utilities::getInstance().isEnoughTimeElapsed(_currentCooldown, _begin)) {
			_currentFrame++;

			if (_currentFrame >= _animations[currentAnimation].size())
				_currentFrame = 0;
		}

		std::vector<Rect> frames = _animations[currentAnimation];
		sprite = frames[_currentFrame];
	}
}