#pragma once
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"

class CheckPhysicsExtension : AbstractGameObjectExtension
{
private: 
	PhysicsFacade _physicsfacade;

	//ask for collisions for subject from physics
	//if collision, call collisionresolution extensions
public:
	static AbstractGameObjectExtension* __stdcall Create() { return new CheckPhysicsExtension(); }
};

