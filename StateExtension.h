#pragma once
#include "AbstractGameObjectExtension.h"

class StateExtension : public AbstractGameObjectExtension
{
private:
	bool _state;

public:
	void changeState();
	static AbstractGameObjectExtension* __stdcall create() { return new StateExtension(); }
};

