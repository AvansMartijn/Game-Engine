#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_CheckPhysicsExtension __declspec(dllexport)
#else
#define GAMEENGINE_CheckPhysicsExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
//#include "PhysicsFacade.h"

//  TODO: KAN DEZE WEG?

/// <summary>
/// Physics
/// </summary>
class GAMEENGINE_CheckPhysicsExtension CheckPhysicsExtension : public AbstractGameObjectExtension {
public:
	CheckPhysicsExtension();
	void doPhysics();
	static AbstractGameObjectExtension* __stdcall create() { return new CheckPhysicsExtension(); }
};

