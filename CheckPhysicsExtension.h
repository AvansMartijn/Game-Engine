#pragma once
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
#include "Physics.h"

class CheckPhysicsExtension : AbstractGameObjectExtension
{
private: 
	Physics _physics;

	//ask for collisions for subject from physics
	//if collision, call collisionresolution extensions
};

