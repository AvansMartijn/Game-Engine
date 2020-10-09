#pragma once
#include "AbstractCollisionResolutionExtension.h"
class CollisionResolutionDefaultExtension : public AbstractCollisionResolutionExtension
{
	//physics do something(subject, subject)
public:
	CollisionResolutionDefaultExtension();

	bool isDefault();
	void resolveCollition(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionDefaultExtension(); }
};

