#pragma once
#include "AbstractGameObjectExtension.h"

// TODO: KAN DEZE WEG?

/// <summary>
/// Vision capabilities
/// </summary>
class VisionExtension : public AbstractGameObjectExtension {
private:
	int _coneRadius;
	int _radius;
	int _direction;
public:
	static AbstractGameObjectExtension* __stdcall create() { return new VisionExtension(); }
};

