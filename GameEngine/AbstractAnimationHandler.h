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
	virtual	void registerAnimations() = 0;
	virtual void animate(std::shared_ptr<GameObject> gameObject) = 0;
	
	std::string getKeyFromMovementType(MovementType movementType);
};

