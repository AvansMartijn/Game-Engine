#pragma once
#include "AbstractGameObjectExtension.h"

// TODO: KAN DEZE WEG?
class SwitchExtension : public AbstractGameObjectExtension {
private:
	bool _state;
public:
	static AbstractGameObjectExtension* __stdcall create() { return new SwitchExtension(); }
};

