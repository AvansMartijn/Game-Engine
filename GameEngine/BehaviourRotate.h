#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Rotate ai behavior
/// </summary>
class BehaviourRotate : public AbstractBehaviour
{
public:
	BehaviourRotate(shared_ptr<GameObject> self, int waitTime);
	int waitTime = 2000;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();
};

