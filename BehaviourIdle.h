#pragma once
#include "AbstractBehaviour.h"

class BehaviourIdle: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();
};

