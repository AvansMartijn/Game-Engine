#pragma once
#include "AbstractAnimationHandler.h"

class EnemyAnimationHandler : public AbstractAnimationHandler
{
public:
	void registerAnimations();
	void animate(std::shared_ptr<GameObject> gameObject);
};

