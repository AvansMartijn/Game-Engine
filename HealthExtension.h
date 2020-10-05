#pragma once
#include "AbstractGameObjectExtension.h"

class HealthExtension : AbstractGameObjectExtension
{
private:
	float _health;


public:
	static AbstractGameObjectExtension* __stdcall Create() { return new HealthExtension(); }
};

