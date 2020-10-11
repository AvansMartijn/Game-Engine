#pragma once
#include "AbstractGameObjectExtension.h"
#include "PhysicsFacade.h"

/// <summary>
/// Movement capabilities
/// </summary>
class MoveExtension : public AbstractGameObjectExtension
{
private:
	PhysicsFacade _physicsFacade;
public:
	MoveExtension();
	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
	void move();
};

