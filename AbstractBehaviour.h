#pragma once
#include <list>
#include "GameObject.h"

/// <summary>
/// Abstract class for ai behavior
/// </summary>
class AbstractBehaviour
{
public:
	AbstractBehaviour(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene);

	virtual void execute() = 0;

	shared_ptr<AbstractBehaviour> behaviourTrue = nullptr;
	shared_ptr<AbstractBehaviour> behaviourFalse = nullptr;
protected:
	shared_ptr<GameObject> _self = nullptr;
	shared_ptr<vector<GameObject>> _scene;

	virtual void executeNextBehaviour(bool isTrue);
};

