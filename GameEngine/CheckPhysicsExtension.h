#pragma once
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"

/// <summary>
/// Physics
/// </summary>
class CheckPhysicsExtension : public AbstractGameObjectExtension
{
private:
	PhysicsFacade _physicsfacade;
public:
	CheckPhysicsExtension();
	void doPhysics(vector<shared_ptr<GameObject>> gameObjectList);
	static AbstractGameObjectExtension* __stdcall create() { return new CheckPhysicsExtension(); }
};

