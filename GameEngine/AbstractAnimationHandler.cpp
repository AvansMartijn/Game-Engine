#include "pch.h"
#include "AbstractAnimationHandler.h"

// TODO: Naar time class
bool AbstractAnimationHandler::isEnoughTimeElapsed(int timeNeeded) {
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	long diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - _begin).count();

	if (diff >= timeNeeded)
		_begin = std::chrono::steady_clock::now();

	return diff >= timeNeeded;
}