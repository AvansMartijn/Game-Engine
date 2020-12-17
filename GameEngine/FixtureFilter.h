#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_FixtureFilter __declspec(dllexport)
#else
#define GAMEENGINE_FixtureFilter __declspec(dllimport)
#endif

typedef signed char	int8;
typedef signed short int16;
typedef signed int int32;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

struct FixtureFilter {
	uint16 categoryBits;
	uint16 maskBits;
	uint16 groupIndex;
};
