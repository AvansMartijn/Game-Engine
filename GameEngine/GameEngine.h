#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif


#include <string>

GAMEENGINE_API std::string EngineDoSomthing();
GAMEENGINE_API std::string EngineDoSomthingElse();
