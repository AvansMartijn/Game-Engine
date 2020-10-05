#pragma once
#include "AbstractGameObjectExtension.h"

class AttackExtension : AbstractGameObjectExtension
{
private:
	int _damage;
	float _range;

	//MS
	int cooldown;
};

