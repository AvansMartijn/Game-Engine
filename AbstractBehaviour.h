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

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	virtual void execute() = 0;

	shared_ptr<AbstractBehaviour> behaviourTrue = nullptr;
	shared_ptr<AbstractBehaviour> behaviourFalse = nullptr;
protected:
	shared_ptr<GameObject> _self = nullptr;
	shared_ptr<vector<GameObject>> _scene;

	/// <summary>
	/// Execute the next behaviour.
	/// </summary>
	/// <param name="isTrue">The state of the next behaviour.</param>
	virtual void executeNextBehaviour(bool isTrue);
};

