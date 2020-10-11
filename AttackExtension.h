#pragma once
#include "AbstractGameObjectExtension.h"

class AttackExtension : public AbstractGameObjectExtension
{
public:
	AttackExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new AttackExtension(); }
};
