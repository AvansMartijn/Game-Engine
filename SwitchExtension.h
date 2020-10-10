#pragma once
#include "AbstractGameObjectExtension.h"

class SwitchExtension : public AbstractGameObjectExtension
{
private:
	bool _state;
	//GameObject _outputGameObject();

public:
	//void SwitchState();

	static AbstractGameObjectExtension* __stdcall create() { return new SwitchExtension(); }
};

