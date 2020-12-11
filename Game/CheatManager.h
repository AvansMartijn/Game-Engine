#pragma once
#include <string>
#include "KeybindingData.h"
#include "CheatCommand.h"

class CheatManager {
private:
	CheatManager();
	static CheatManager _instance;
public:
	// TODO: PRIVATE
	std::map<std::string, std::unique_ptr<CheatCommand>> cheatList;
	std::map<std::string, std::string> cheatInformation;

	static CheatManager& getInstance() { return _instance; }

	CheatManager(const CheatManager&) = delete;
	CheatManager(CheatManager&&) = delete;
	CheatManager& operator=(const CheatManager&) = delete;
	CheatManager& operator=(CheatManager&&) = delete;

	/// <summary>
	/// Get's the cheat information.
	/// </summary>
	/// <returns>The cheat information</returns>
	std::map<std::string, std::string> getCheatInformation();

	/// <summary>
	/// Register all the cheats.
	/// </summary>
	void initializeCheats();

	/// <summary>
	/// Checks if there is a cheat with the given name.
	/// </summary>
	/// <param name="cheat">The name of the cheat we want to search for.</param>
	/// <returns>If there is a cheat with the given name.</returns>
	bool isCheat(std::string cheatName);

	/// <summary>
	/// Execute the cheat with the givenName
	/// </summary>
	/// <param name="cheat"></param>
	/// <returns></returns>
	bool executeCheat(std::string cheatName);
};
