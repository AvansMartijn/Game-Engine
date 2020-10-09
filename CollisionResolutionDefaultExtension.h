#pragma once
#include "AbstractCollisionResolutionExtension.h"
class CollisionResolutionDefaultExtension : public AbstractCollisionResolutionExtension
{
	//physics do something(subject, subject)
public:
	static AbstractCollisionResolutionExtension* __stdcall create() { return new CollisionResolutionDefaultExtension(); }
};

