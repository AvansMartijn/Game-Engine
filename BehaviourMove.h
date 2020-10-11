#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Move ai behavior
/// </summary>
class BehaviourMove: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();

	/// <summary>
	/// Looks if the object can be moved.
	/// </summary>
	/// <returns>If the object can be moved</returns>
	bool isMovable();

	/// <summary>
	/// If a wall is hit.
	/// </summary>
	/// <returns>If the wall is hit</returns>
	bool isWallHit();
};

