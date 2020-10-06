#pragma once
#include "AbstractGameObjectExtension.h"
class AiExtension : AbstractGameObjectExtension
{


public:
	void DoAi();



	static AbstractGameObjectExtension* __stdcall Create() { return new AiExtension(); }
};

