#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Utilities __declspec(dllexport)
#else
#define GAMEENGINE_Utilities __declspec(dllimport)
#endif
#include <chrono>

class GAMEENGINE_Utilities Utilities
{
private:
	Utilities();
	static Utilities instance;
public:
	static Utilities& getInstance() { return instance; }

	Utilities(const Utilities&) = delete;
	Utilities(Utilities&&) = delete;
	Utilities& operator=(const Utilities&) = delete;
	Utilities& operator=(Utilities&&) = delete;

	bool isEnoughTimeElapsed(int timeNeeded, std::chrono::steady_clock::time_point& timePoint);
};

