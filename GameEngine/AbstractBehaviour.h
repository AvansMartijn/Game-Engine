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
class GAMEENGINE_AbstractBehaviour AbstractBehaviour
{
public:
	AbstractBehaviour(shared_ptr<GameObject> self);

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	virtual void execute() = 0;

	/// <summary>
	/// If enough time has elapsed.
	/// </summary>
	/// <param name="timeNeeded">The time we need to be elapsed.</param>
	/// <returns>If enough time has elapsed.</returns>
	bool isEnoughTimeElapsed(int timeNeeded);

	shared_ptr<AbstractBehaviour> behaviourTrue = nullptr;
	shared_ptr<AbstractBehaviour> behaviourFalse = nullptr;
protected:
	shared_ptr<GameObject> _self = nullptr;
	std::chrono::steady_clock::time_point _begin;

	/// <summary>
	/// Execute the next behaviour.
	/// </summary>
	/// <param name="isTrue">The state of the next behaviour.</param>
	virtual void executeNextBehaviour(bool isTrue);
};

