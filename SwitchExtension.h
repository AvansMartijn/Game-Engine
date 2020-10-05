#pragma once
#include "AbstractGameObjectExtension.h"

class SwitchExtension : AbstractGameObjectExtension
{
private:
	bool _state;
	GameObject _outputGameObject();

public:
	void SwitchState();
};

