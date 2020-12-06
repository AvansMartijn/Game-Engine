#pragma once
#include <string>
#include "KeybindingData.h"
#include "CheatCommand.h"

class CheatManager
{
private:
	CheatManager();
	static CheatManager _instance;
public:
	std::map<std::string, std::unique_ptr<CheatCommand>> CheatList;
	std::map<std::string, std::string> CheatInformation;
	static CheatManager& getInstance() { return _instance; }

	CheatManager(const CheatManager&) = delete;
	CheatManager(CheatManager&&) = delete;
	CheatManager& operator=(const CheatManager&) = delete;
	CheatManager& operator=(CheatManager&&) = delete;

	std::map<std::string, std::string> getCheatInformation();
	void initializeCheats();
	bool isCheat(std::string Cheat);
	void executeCheat(std::string Cheat);
};
