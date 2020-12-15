#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Utilities __declspec(dllexport)
#else
#define GAMEENGINE_Utilities __declspec(dllimport)
#endif
#include <chrono>
#include <string>
#include <random>
#include <cassert>

class GAMEENGINE_Utilities Utilities
{
private:
	Utilities();
	static Utilities instance;

	/// <summary>
	/// Creates a random engine instance.
	/// </summary>
	/// <returns>The random engine instance.</returns>
	std::default_random_engine& getRandomEngine() const;
public:
	static Utilities& getInstance() { return instance; }

	Utilities(const Utilities&) = delete;
	Utilities(Utilities&&) = delete;
	Utilities& operator=(const Utilities&) = delete;
	Utilities& operator=(Utilities&&) = delete;
	
	/// <summary>
	/// Checks if enough time has elapsed from the given point.
	/// </summary>
	/// <param name="timeNeeded">The time difference we want in ms.</param>
	/// <param name="timePoint">The start time.</param>
	/// <returns>If enough time has passed.</returns>
	bool isEnoughTimeElapsed(int timeNeeded, std::chrono::steady_clock::time_point& timePoint) const;

	/// <summary>
	/// Converts a given time point to a long.
	/// </summary>
	/// <param name="time">The time point we want to convert.</param>
	/// <returns>The time point as number.</returns>
	long convertTimeToLong(std::chrono::steady_clock::time_point time) const;

	/// <summary>
	/// Trim the string.
	/// </summary>
	/// <param name="str">The string</param>
	void trim(std::string& str) const;

	/// <summary>
	/// Trim the left side of the string.
	/// </summary>
	/// <param name="str">The string</param>
	void leftTrim(std::string& str) const;

	/// <summary>
	/// Trim the right side of the string.
	/// </summary>
	/// <param name="str">The string</param>
	void rightTrim(std::string& str) const;

	/// <summary>
	/// Generates a random int between the two given points.
	/// </summary>
	/// <param name="low">The lowest possible number.</param>
	/// <param name="high">The highest possible number.</param>
	/// <returns>The random number.</returns>
	int getRandomInt(int low, int high) const;
};

