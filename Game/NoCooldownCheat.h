#pragma once
#include "CheatCommand.h"

class NoCooldownCheat : public CheatCommand {
public:
	/// <summary>
	/// Execute the cheat.
	/// </summary>
	/// <returns>If the cheat was executed succesfully.</returns>
	bool execute();
};

