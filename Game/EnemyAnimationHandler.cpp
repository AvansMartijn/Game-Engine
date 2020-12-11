#include "EnemyAnimationHandler.h"
#include "GameObject.h"
#include <Physics.h>
#include "Utilities.h"

void EnemyAnimationHandler::registerAnimations() {
	//_animations
	_currentFrame = 0;
	_currentCooldown = 1000;

	std::vector<Rect> frames;

	// Idle
	frames.push_back(Rect{ 23, 1, 86, 76 });
	frames.push_back(Rect{ 185, 1, 86, 76 });
	frames.push_back(Rect{ 347, 2, 86, 75 });
	frames.push_back(Rect{ 509, 3, 86, 74 });
	frames.push_back(Rect{ 671, 4, 84, 73 });
	frames.push_back(Rect{ 833, 4, 84, 73 });
	frames.push_back(Rect{ 995, 3, 85, 74 });
	frames.push_back(Rect{ 1157, 2, 86, 75 });
	frames.push_back(Rect{ 1319, 1, 86, 76 });
	frames.push_back(Rect{ 1481, 1, 86, 76 });
	frames.push_back(Rect{ 1643, 1, 86, 76 });
	frames.push_back(Rect{ 1805, 1, 86, 76 });

	_animations.insert(make_pair(KEY_IDLE, frames));

	// Running
	frames.clear();
	frames.push_back(Rect{ 23, 674, 86, 75 });
	frames.push_back(Rect{ 185, 675, 86, 74 });
	frames.push_back(Rect{ 347, 677, 87, 72 });
	frames.push_back(Rect{ 509, 676, 85, 73 });
	frames.push_back(Rect{ 671, 674, 85, 75 });
	frames.push_back(Rect{ 833, 675, 86, 74 });
	frames.push_back(Rect{ 995, 677, 86, 72 });
	frames.push_back(Rect{ 1157, 676, 86, 73 });

	_animations.insert(make_pair(KEY_RUNNING, frames));

	// Attacking
	frames.clear();
	frames.push_back(Rect{ 23, 1920, 86, 77 });
	frames.push_back(Rect{ 184, 1925, 87, 72 });
	frames.push_back(Rect{ 345, 1929, 88, 68 });
	frames.push_back(Rect{ 507, 1931, 88, 66 });
	frames.push_back(Rect{ 669, 1931, 88, 66 });
	frames.push_back(Rect{ 830, 1926, 89, 71 });

	_animations.insert(make_pair(KEY_ATTACKING, frames));
}

void EnemyAnimationHandler::animate(std::shared_ptr<GameObject> gameObject) {
	if (gameObject->hasExtension(typeid(MoveExtension))) {
		shared_ptr<MoveExtension> moveExtension = gameObject->getExtension<MoveExtension>();
		shouldFlipRight = moveExtension->isLookingToRight;

		if (getKeyFromMovementType(moveExtension->currentMovementType) != currentAnimation) {
			_currentFrame = 0;

			Vec2 velocity = Physics::getInstance().getLinearVelocity(gameObject);

			if (moveExtension->currentMovementType == MovementType::RUNNING) {
				currentAnimation = KEY_RUNNING;
				_currentCooldown = 200;
			}
			else if (moveExtension->currentMovementType == MovementType::ATTACKING) {
				currentAnimation = KEY_ATTACKING;
				_currentCooldown = 200;
			}
			else if (moveExtension->currentMovementType == MovementType::IDLE) {
				currentAnimation = KEY_IDLE;
				_currentCooldown = 500;
			}
		}
		else if (Utilities::getInstance().isEnoughTimeElapsed(_currentCooldown, _begin)) {
			_currentFrame++;

			if (_currentFrame == _animations[currentAnimation].size())
				_currentFrame = 0;
		}

		std::vector<Rect> frames = _animations[currentAnimation];
		sprite = frames[_currentFrame];
	}
}
