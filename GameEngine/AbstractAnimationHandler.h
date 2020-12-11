#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractAnimationHandler __declspec(dllexport)
#else
#define GAMEENGINE_AbstractAnimationHandler __declspec(dllimport)
#endif
#include "Rect.h"
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include "MovementType.h"

class GameObject;
class GAMEENGINE_AbstractAnimationHandler AbstractAnimationHandler {
protected:
	std::map<std::string, std::vector<Rect>> _animations;
	std::string currentAnimation;
	int _currentFrame;
	int _currentCooldown;
	std::chrono::steady_clock::time_point _begin;
public:
	const std::string KEY_IDLE = "IDLE";
	const std::string KEY_RUNNING = "RUNNING";
	const std::string KEY_JUMPING = "JUMPING";
	const std::string KEY_ATTACKING = "ATTACKING";
	const std::string KEY_AFK = "AFK";
	const std::string KEY_HURTING = "HURTING";

	Rect sprite;
	bool shouldFlipLeft;

	/// <summary>
	/// Register the animations.
	/// </summary>
	virtual	void registerAnimations() = 0;

	/// <summary>
	/// Animate the given game object.
	/// </summary>
	/// <param name="gameObject">The game object we want to animate.</param>
	virtual void animate(std::shared_ptr<GameObject> gameObject) = 0;
	
	/// <summary>
	/// Converts a movement type to a key.
	/// </summary>
	/// <param name="movementType">The movement type we want to convert.</param>
	/// <returns>The movement type as key.</returns>
	std::string getKeyFromMovementType(MovementType movementType);
};

