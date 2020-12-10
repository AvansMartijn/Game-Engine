#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_MoveExtension __declspec(dllexport)
#else
#define GAMEENGINE_MoveExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "MovementType.h"
#include "GameObject.h"

/// <summary>
/// Movement capabilities
/// </summary>
class GAMEENGINE_MoveExtension MoveExtension : public AbstractGameObjectExtension
{
public:
	MoveExtension();
	int jumpCounter;
	int leftArmCounter;
	int rightArmCounter;

	MovementType currentMovementType;
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

	/// <summary>
	/// Move the subject.
	/// </summary>
	/// <param name="movementX">The x movement.</param>
	/// <param name="movementY">The y movement.</param>
	void move(float movementX, float movementY);

	int getLeftArmCounter();
	int getRightArmCounter();

	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
};

