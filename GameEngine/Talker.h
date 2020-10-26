#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_TALKER __declspec(dllexport)
#else
#define GAMEENGINE_TALKER __declspec(dllimport)
#endif

#include <string>

class GAMEENGINE_TALKER Talker
{

public:
	std::string Talk();
};

