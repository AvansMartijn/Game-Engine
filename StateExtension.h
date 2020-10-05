#pragma once
#include "AbstractGameObjectExtension.h"

class StateExtension : AbstractGameObjectExtension
{
private:
	bool _state;

public:
	void changeState();

	static AbstractGameObjectExtension* __stdcall Create() { return new StateExtension(); }
};

