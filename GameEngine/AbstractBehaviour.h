#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractBehaviour __declspec(dllexport)
#else
#define GAMEENGINE_AbstractBehaviour __declspec(dllimport)
#endif
#include <list>
#include "GameObject.h"
#include <chrono>

/// <summary>
/// Abstract class for ai behavior
/// </summary>
class GAMEENGINE_AbstractBehaviour AbstractBehaviour {
protected:
	shared_ptr<GameObject> _self = nullptr;
	std::chrono::steady_clock::time_point _begin;

	/// <summary>
	/// Execute the next behaviour.
	/// </summary>
	/// <param name="isTrue">The state of the next behaviour.</param>
	virtual void executeNextBehaviour(bool isTrue);
public:
	// Both these pointers should not own the behaviour.
	AbstractBehaviour* behaviourTrue;
	AbstractBehaviour* behaviourFalse;

	AbstractBehaviour(shared_ptr<GameObject> self);

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	virtual void execute() = 0;
};

