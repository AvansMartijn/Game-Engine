#pragma once
#include <string>
#include "KeybindingData.h"

class ControllManager
{
private:
	ControllManager();
	static ControllManager _instance;
public:
	KeybindingData toggleFPSKey;
	KeybindingData walkLeftKey;
	KeybindingData walkRightKey;
	KeybindingData stopKey;
	KeybindingData jumpKey;
	KeybindingData equipPortalKey;
	KeybindingData equipThrusterKey;
	KeybindingData equipGlueKey;

	static ControllManager& getInstance() { return _instance; }
	
	ControllManager(const ControllManager&) = delete;
	ControllManager(ControllManager&&) = delete;
	ControllManager& operator=(const ControllManager&) = delete;
	ControllManager& operator=(ControllManager&&) = delete;

	void saveControlls();
	bool validKey(SDL_Scancode key, std::string Action);
	void initializeControlls();
	void updateControll(std::string Action, std::string userKey, SDL_Scancode userSDLKey);
};