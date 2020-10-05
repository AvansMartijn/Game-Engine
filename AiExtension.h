#pragma once
#include "AbstractGameObjectExtension.h"
class AiExtension : AbstractGameObjectExtension
{


public:
	static AbstractGameObjectExtension* __stdcall Create() { return new AiExtension(); }
};

