#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_CollisionResolutionPortalExtension __declspec(dllexport)
#else
#define GAMEENGINE_CollisionResolutionPortalExtension __declspec(dllimport)
#endif

#include "AbstractCollisionResolutionExtension.h"
#include "GameObject.h"
#include "Physics.h"

class GAMEENGINE_CollisionResolutionPortalExtension CollisionResolutionPortalExtension : public AbstractCollisionResolutionExtension{
private:
	shared_ptr<GameObject> _linkedPortal;
public:
	bool isActive = false;
	CollisionResolutionPortalExtension();
	std::string exitSide;

	/// <summary>
	/// Reverses a float number.
	/// </summary>
	/// <param name="number">The number we want to reverse.</param>
	/// <returns>The reversed float.</returns>
	float reverseFloat(float number);

	/// <summary>
	/// Get's the side which the game object goes in.
	/// </summary>
	/// <param name="exitSide">The output side.</param>
	/// <returns>The side which the gameobject goes in.</returns>
	std::string getEntrySide(std::string exitSide);

	/// <summary>
	/// If the collision is default.
	/// </summary>
	/// <returns>If the collision is default.</returns>
	bool isDefault();

	/// <summary>
	/// Resolve the collision
	/// </summary>
	/// <param name="inputObject">The gameObject which we want to resolve with.</param>
	void resolveCollision(shared_ptr<GameObject> inputObject);

	/// <summary>
	/// Link two game objects.
	/// </summary>
	/// <param name="linkedPortal">The game object we want to link with.</param>
	void link(shared_ptr<GameObject> linkedPortal);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionPortalExtension(); }
	static std::string __stdcall getType() { return "CollisionResolutionPortalExtension"; }
};

