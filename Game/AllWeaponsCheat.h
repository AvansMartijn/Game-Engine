#pragma once
#include "CheatCommand.h"

class AllWeaponsCheat : public CheatCommand {
public:
	/// <summary>
	/// Execute the cheat.
	/// </summary>
	/// <returns>If the cheat was executed succesfully.</returns>
	bool execute();
};

