#pragma once
#include "AbstractGameObjectExtension.h"

// TODO: MAG DEZE WEG?
/// <summary>
/// Attack capabilities
/// </summary>
class AttackExtension : public AbstractGameObjectExtension {
public:
	AttackExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new AttackExtension(); }
};
