#pragma once
#include "AbstractAnimationHandler.h"

class EnemyAnimationHandler : public AbstractAnimationHandler {
public:
	/// <summary>
	/// Register the animations.
	/// </summary>
	void registerAnimations();

	/// <summary>
	/// Animate the given game object.
	/// </summary>
	/// <param name="gameObject">The game object we want to animate.</param>
	void animate(GameObject* gameObject);
};

