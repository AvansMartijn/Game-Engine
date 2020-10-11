#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Attack behavior
/// </summary>
class BehaviourAttack: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();

	bool canAttack();
};

