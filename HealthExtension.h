#pragma once
#include "AbstractGameObjectExtension.h"

class HealthExtension : AbstractGameObjectExtension
{
private:
	float _health;


public:
	static AbstractGameObjectExtension* __stdcall create() { return new HealthExtension(); }
};

