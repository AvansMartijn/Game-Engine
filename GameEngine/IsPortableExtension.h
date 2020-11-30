#pragma once
#include "AbstractGameObjectExtension.h"

class IsPortableExtension : public AbstractGameObjectExtension
{
public:
	IsPortableExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new IsPortableExtension(); }
};

