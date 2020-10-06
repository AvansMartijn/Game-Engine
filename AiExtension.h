#pragma once
#include "AbstractGameObjectExtension.h"
class AiExtension : AbstractGameObjectExtension
{


public:
	void doAi();



	static AbstractGameObjectExtension* __stdcall create() { return new AiExtension(); }
};

