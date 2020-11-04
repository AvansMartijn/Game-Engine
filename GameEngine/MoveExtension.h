#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_MoveExtension __declspec(dllexport)
#else
#define GAMEENGINE_MoveExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "MovementType.h"

/// <summary>
/// Movement capabilities
/// </summary>
class GAMEENGINE_MoveExtension MoveExtension : public AbstractGameObjectExtension
{
private:
	//PhysicsFacade _physicsFacade;
public:

	MoveExtension();
	int jumpCounter;

	MovementTypes currentMovementType;
	bool isLookingToRight;

	/// <summary>
	/// Checks if the player can jump.
	/// </summary>
	/// <returns>If the player can jump.</returns>
	bool canJump();

	/// <summary>
	/// Resets the player data.
	/// </summary>
	void reset();

	void move();

	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
};

