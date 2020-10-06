#pragma once
#include "AbstractGameObjectExtension.h"

class VisionExtension : AbstractGameObjectExtension
{
private:
	int _coneRadius;
	int _radius;
	int _direction;

public:
	static AbstractGameObjectExtension* __stdcall create() { return new VisionExtension(); }
};

