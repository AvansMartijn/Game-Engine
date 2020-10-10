#pragma once
#include "AbstractGameObjectExtension.h"
class AiExtension : public AbstractGameObjectExtension
{


public:
	void doAi();
	AiExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new AiExtension(); }
};

