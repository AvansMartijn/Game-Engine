#pragma once
#include "AbstractGameObjectExtension.h"

class DoesDamageExtension : public AbstractGameObjectExtension
{
public:
	int damage;
	DoesDamageExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new DoesDamageExtension(); }
};

