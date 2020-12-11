#pragma once
#include "CheatCommand.h"

class GodmodeCheat : public CheatCommand {
public:
	/// <summary>
	/// Execute the cheat.
	/// </summary>
	/// <returns>If the cheat was executed succesfully.</returns>
	bool Execute();
};

