#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_MoveExtension __declspec(dllexport)
#else
#define GAMEENGINE_MoveExtension __declspec(dllimport)
#endif
// TODO: We moeten in de game kunnen checken of iets een extensie heeft, voor nu gebruiken we alleen deze extensions, maar vrij zeker dat we ze straks allemaal moeten exposen.
#include "AbstractGameObjectExtension.h"
#include "PhysicsFacade.h"

/// <summary>
/// Movement capabilities
/// </summary>
class GAMEENGINE_MoveExtension MoveExtension : public AbstractGameObjectExtension
{
private:
	PhysicsFacade _physicsFacade;
public:
	MoveExtension();
	static AbstractGameObjectExtension* __stdcall create() { return new MoveExtension(); }
	void move();
};

