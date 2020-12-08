#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_EntityMovementExtension __declspec(dllexport)
#else
#define GAMEENGINE_EntityMovementExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"

class GAMEENGINE_EntityMovementExtension EntityMovementExtension : public AbstractGameObjectExtension
{
private:
public:
	EntityMovementExtension();

	static AbstractGameObjectExtension* __stdcall create() { return new EntityMovementExtension(); }
	bool isLookingRight;
	bool shouldMove;
	bool shouldMoveToRight;

	void move();
};

