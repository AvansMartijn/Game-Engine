#include "ControllManager.h"
#include "GameSettings.h"

ControllManager ControllManager::_instance;

ControllManager::ControllManager() {
}

void ControllManager::saveControlls()
{
	SaveKeybindings kb;
	kb.toggleFPSKey = this->toggleFPSKey;
	kb.walkLeftKey = this->walkLeftKey;
	kb.walkRightKey = this->walkRightKey;
	kb.jumpKey = this->jumpKey;
	kb.equipPortalKey = this->equipPortalKey;
	kb.equipThrusterKey = this->equipThrusterKey;
	kb.equipGlueKey = this->equipGlueKey;

	GameSettings::getInstance().saveGame.settings.cm = kb;
	GameSettings::getInstance().save();
}

void ControllManager::initializeControlls()
{
	//TODO READ FROM SAVEFILE
	this->toggleFPSKey = KeybindingData("F3",SDL_SCANCODE_F3);
	this->walkLeftKey = KeybindingData("A", SDL_SCANCODE_A);
	this->walkRightKey = KeybindingData("D", SDL_SCANCODE_D);
	this->jumpKey = KeybindingData("SPACE", SDL_SCANCODE_SPACE);
	this->equipPortalKey = KeybindingData("1", SDL_SCANCODE_1);
	this->equipThrusterKey = KeybindingData("2", SDL_SCANCODE_2);
	this->equipGlueKey = KeybindingData("3", SDL_SCANCODE_3);
}

void ControllManager::updateControll(std::string Action, std::string userKey, SDL_Scancode userSDLKey)
{
	if (Action == "toggleFPS") {
		this->toggleFPSKey.isDefault = false;
		this->toggleFPSKey.userKey = userKey;
		this->toggleFPSKey.userSDLKey = userSDLKey;
	}
	else if (Action == "walkLeft") {
		this->walkLeftKey.isDefault = false;
		this->walkLeftKey.userKey = userKey;
		this->walkLeftKey.userSDLKey = userSDLKey;
	}
	else if (Action == "walkRight") {
		this->walkRightKey.isDefault = false;
		this->walkRightKey.userKey = userKey;
		this->walkRightKey.userSDLKey = userSDLKey;
	}
	else if (Action == "jump") {
		this->jumpKey.isDefault = false;
		this->jumpKey.userKey = userKey;
		this->jumpKey.userSDLKey = userSDLKey;
	}
	else if (Action == "equipPortal") {
		this->equipPortalKey.isDefault = false;
		this->equipPortalKey.userKey = userKey;
		this->equipPortalKey.userSDLKey = userSDLKey;
	}
	else if (Action == "equipThruster") {
		this->equipThrusterKey.isDefault = false;
		this->equipThrusterKey.userKey = userKey;
		this->equipThrusterKey.userSDLKey = userSDLKey;
	}
	else if (Action == "equipGlue") {
		this->equipGlueKey.isDefault = false;
		this->equipGlueKey.userKey = userKey;
		this->equipGlueKey.userSDLKey = userSDLKey;
	}
}
