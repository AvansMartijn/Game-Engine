#include "pch.h"
#include "Utilities.h"

Utilities Utilities::instance;

Utilities::Utilities() {}

bool Utilities::isEnoughTimeElapsed(int timeNeeded, std::chrono::steady_clock::time_point& timePoint) {
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	long diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - timePoint).count();

	if (diff >= timeNeeded)
		timePoint = std::chrono::steady_clock::now();

	return diff >= timeNeeded;
}