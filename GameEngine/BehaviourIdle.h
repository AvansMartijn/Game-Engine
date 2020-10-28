#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Idle ai behavior
/// </summary>
class BehaviourIdle : public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();
};

