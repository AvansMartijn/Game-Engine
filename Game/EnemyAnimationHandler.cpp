#include "EnemyAnimationHandler.h"
void EnemyAnimationHandler::registerAnimations() {

}

void EnemyAnimationHandler::animate(std::shared_ptr<GameObject> gameObject) {
	sprite = Rect{ 23, 1, 86, 76 };
	shouldFlipRight = !shouldFlipRight;
	int a = 0;
}
