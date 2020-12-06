#pragma once
#include "AbstractGameObjectExtension.h"

class PlayerMoveExtension : public AbstractGameObjectExtension {
public:
	PlayerMoveExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new PlayerMoveExtension(); }

	void move();
};

