#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Move ai behavior
/// </summary>
class BehaviourMove : public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();
};

