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
	static const std::string LOOK_RIGHT;
	static const std::string RUN_RIGHT;
	static const std::string JUMP_RIGHT;
	static const std::string FALL_RIGHT;
	static const std::string ATTACK_RIGHT;
	static const std::string LOOK_LEFT;
	static const std::string RUN_LEFT;
	static const std::string JUMP_LEFT;
	static const std::string FALL_LEFT;
	static const std::string ATTACK_LEFT;

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

	/// <summary>
	/// Move the subject.
	/// </summary>
	/// <param name="movementX">The x movement.</param>
	/// <param name="movementY">The y movement.</param>
	void move(float movementX, float movementY);

	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
};

