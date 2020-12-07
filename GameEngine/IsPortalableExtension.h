#pragma once
#include "AbstractGameObjectExtension.h"

class IsPortalableExtension : public AbstractGameObjectExtension
{
public:
	IsPortalableExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new IsPortalableExtension(); }
};

