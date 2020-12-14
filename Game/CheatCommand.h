#pragma once
class CheatCommand {
public:
	/// <summary>
	/// Execute the cheat.
	/// </summary>
	/// <returns>If the cheat was executed succesfully.</returns>
	virtual bool execute() = 0;
};

