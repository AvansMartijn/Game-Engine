#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_CheckPhysicsExtension __declspec(dllexport)
#else
#define GAMEENGINE_CheckPhysicsExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
//#include "PhysicsFacade.h"

/// <summary>
/// Physics
/// </summary>
class GAMEENGINE_CheckPhysicsExtension CheckPhysicsExtension : public AbstractGameObjectExtension
{
private:
	//PhysicsFacade _physicsfacade;
public:
	CheckPhysicsExtension();
	void doPhysics();
	static AbstractGameObjectExtension* __stdcall create() { return new CheckPhysicsExtension(); }
};

