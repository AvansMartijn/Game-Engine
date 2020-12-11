#include "pch.h"
#include "Utilities.h"

Utilities Utilities::instance;

Utilities::Utilities() {}

bool Utilities::isEnoughTimeElapsed(int timeNeeded, std::chrono::steady_clock::time_point& timePoint) {
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - timePoint).count();

	if (diff >= timeNeeded)
		timePoint = std::chrono::steady_clock::now();

	return diff >= timeNeeded;
}

long Utilities::convertTimeToLong(std::chrono::steady_clock::time_point time) {
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(time);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

	return (long)value.count();
}

void Utilities::trim(std::string& str) {
	leftTrim(str);
	rightTrim(str);
}

void Utilities::leftTrim(std::string& str) {
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !std::isspace(ch);
	}));
}

void Utilities::rightTrim(std::string& str) {
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
	}).base(), str.end());
}

std::default_random_engine& Utilities::getRandomEngine() {
	static std::random_device rd{};
	static std::default_random_engine re{ rd() };

	return re;
}

int Utilities::getRandomInt(int low, int high) {
	assert(high > low);
	std::uniform_int_distribution<int> d{ low, high - 1 };

	return d(getRandomEngine());
}