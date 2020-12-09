#pragma once
#include "AbstractBehaviour.h"
#include "Scene.h"
#include "HealthExtension.h"

/// <summary>
/// Attack behavior
/// </summary>
class BehaviourAttack : public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();
};

