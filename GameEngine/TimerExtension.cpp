#include "pch.h"
#include "TimerExtension.h"

TimerExtension::TimerExtension() {
	type = "TimerExtension";
	_creationTime = std::chrono::steady_clock::now();
	//default expires after 5 seconds
	_expiresAfter = 5000;
}

std::chrono::steady_clock::time_point TimerExtension::getCreationTime() {
	return _creationTime;
}

long TimerExtension::getExpiresAfter() {
	return _expiresAfter;
}

bool TimerExtension::isExpired() {
	auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _creationTime).count();
	if (timePassed >= _expiresAfter)
		return true;

	return false;
}

void TimerExtension::setExpiresAfter(int miliseconds) {
	_expiresAfter = miliseconds;
}



