#pragma once
#include "AbstractGameObjectExtension.h"

class AttackExtension : AbstractGameObjectExtension
{
private:
	/*int _damage;
	float _range;*/

	//MS
	//int _cooldown;


public:

	static AbstractGameObjectExtension* __stdcall create() { return new AttackExtension(); }
};

