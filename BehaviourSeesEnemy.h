#pragma once
#include "AbstractBehaviour.h"

class BehaviourSeesEnemy: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();
};

