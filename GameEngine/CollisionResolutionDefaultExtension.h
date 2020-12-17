#pragma once
#include "AbstractCollisionResolutionExtension.h"

class CollisionResolutionDefaultExtension : public AbstractCollisionResolutionExtension {
public:
	CollisionResolutionDefaultExtension();

	/// <summary>
	/// If the collision is default.
	/// </summary>
	/// <returns>If the collision is default.</returns>
	bool isDefault();

	/// <summary>
	/// Resolve the collision
	/// </summary>
	/// <param name="otherObject">The gameObject which we want to resolve with.</param>
	void resolveCollision(GameObject* otherObject);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionDefaultExtension(); }
	static std::string __stdcall getType() { return "CollisionResolutionDefaultExtension"; }

};

