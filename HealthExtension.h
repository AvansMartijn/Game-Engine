#pragma once
#include "AbstractGameObjectExtension.h"

class HealthExtension : AbstractGameObjectExtension
{
public:
	static AbstractGameObjectExtension* __stdcall create() { return new HealthExtension(); }
};

