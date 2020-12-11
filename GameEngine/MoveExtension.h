#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_MoveExtension __declspec(dllexport)
#else
#define GAMEENGINE_MoveExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "MovementType.h"
#include "GameObject.h"
#include <chrono>

/// <summary>
/// Movement capabilities
/// </summary>
class GAMEENGINE_MoveExtension MoveExtension : public AbstractGameObjectExtension {
private:
	std::chrono::steady_clock::time_point _afkTime;
public:
	MoveExtension();
	int jumpCounter;
	int leftArmCounter;
	int rightArmCounter;

	MovementType currentMovementType;
	bool isLookingToLeft;

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

	/// <summary>
	/// Move on the x-axis.
	/// </summary>
	/// <param name="movementX">The movement on the x-axis.</param>
	void moveX(float movementX);

	/// <summary>
	/// Move on the y-axis.
	/// </summary>
	/// <param name="movementY">The movement on the y-axis.</param>
	void moveY(float movementY);

	/// <summary>
	/// Update the current movement state.
	/// </summary>
	void updateState();

	/// <summary>
	/// Get's the amount of collisions for the left arm.
	/// </summary>
	/// <returns>The amount of collision for the left arm.</returns>
	int getLeftArmCounter();

	/// <summary>
	/// Get's the amount of collisions for the right arm.
	/// </summary>
	/// <returns>The amount of collision for the right arm.</returns>
	int getRightArmCounter();

	/// <summary>
	/// Resets the afk timer.
	/// </summary>
	void resetAfkTime();

	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
};

