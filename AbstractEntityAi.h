#pragma once
#include <list>
#include "GameObject.h"

/// <summary>
/// Abstract class for entity ai
/// </summary>
class AbstractEntityAI
{
public:
	AbstractEntityAI();
	virtual void createBehaviourTree(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene) = 0;
};
