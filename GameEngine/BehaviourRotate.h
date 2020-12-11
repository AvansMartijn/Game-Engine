#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Rotate ai behavior
/// </summary>
class BehaviourRotate : public AbstractBehaviour {
private:
	int _waitTime;
public:
	BehaviourRotate(shared_ptr<GameObject> self, int waitTime);

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();
};

