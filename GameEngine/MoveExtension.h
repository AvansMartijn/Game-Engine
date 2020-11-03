#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_MoveExtension __declspec(dllexport)
#else
#define GAMEENGINE_MoveExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"

/// <summary>
/// Movement capabilities
/// </summary>
class GAMEENGINE_MoveExtension MoveExtension : public AbstractGameObjectExtension
{
private:
	//PhysicsFacade _physicsFacade;
public:
	MoveExtension();
	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
	void move();
};

