#pragma once
#include "AbstractGameObjectExtension.h"

/// <summary>
/// Health
/// </summary>
class HealthExtension : AbstractGameObjectExtension
{
public:
	static AbstractGameObjectExtension* __stdcall create() { return new HealthExtension(); }
};

