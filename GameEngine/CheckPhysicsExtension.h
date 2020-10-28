#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_CheckPhysicsExtension __declspec(dllexport)
#else
#define GAMEENGINE_CheckPhysicsExtension __declspec(dllimport)
#endif
// TODO: We moeten in de game kunnen checken of iets een extensie heeft, voor nu gebruiken we alleen deze extensions, maar vrij zeker dat we ze straks allemaal moeten exposen.
#include "AbstractGameObjectExtension.h"
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"

/// <summary>
/// Physics
/// </summary>
class GAMEENGINE_CheckPhysicsExtension CheckPhysicsExtension : public AbstractGameObjectExtension
{
private:
	PhysicsFacade _physicsfacade;
public:
	CheckPhysicsExtension();
	void doPhysics(vector<shared_ptr<GameObject>> gameObjectList);
	static AbstractGameObjectExtension* __stdcall create() { return new CheckPhysicsExtension(); }
};

