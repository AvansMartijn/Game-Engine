#pragma once
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"

class CheckPhysicsExtension : public AbstractGameObjectExtension
{
private: 
	PhysicsFacade _physicsfacade;


	//ask for collisions for subject from physics
	//if collision, call collisionresolution extensions
public:
	CheckPhysicsExtension();
	void doPhysics(vector<shared_ptr<GameObject>> gameObjectList);
	static AbstractGameObjectExtension* __stdcall create() { return new CheckPhysicsExtension(); }
};

