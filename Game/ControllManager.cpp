#include "ControllManager.h"
#include "GameSettings.h"

ControllManager ControllManager::_instance;

ControllManager::ControllManager() {}

void ControllManager::resetControls() {
	this->toggleFPSKey.isDefault = true;
	this->toggleFPSKey.userKey.clear();
	this->toggleFPSKey.userSDLKey = SDL_SCANCODE_0;

	this->walkLeftKey.isDefault = true;
	this->walkLeftKey.userKey.clear();
	this->walkLeftKey.userSDLKey = SDL_SCANCODE_0;

	this->walkRightKey.isDefault = true;
	this->walkRightKey.userKey.clear();
	this->walkRightKey.userSDLKey = SDL_SCANCODE_0;

	this->stopKey.isDefault = true;
	this->stopKey.userKey.clear();
	this->stopKey.userSDLKey = SDL_SCANCODE_0;

	this->jumpKey.isDefault = true;
	this->jumpKey.userKey.clear();
	this->jumpKey.userSDLKey = SDL_SCANCODE_0;

	this->equipPortalKey.isDefault = true;
	this->equipPortalKey.userKey.clear();
	this->equipPortalKey.userSDLKey = SDL_SCANCODE_0;

	this->equipThrusterKey.isDefault = true;
	this->equipThrusterKey.userKey.clear();
	this->equipThrusterKey.userSDLKey = SDL_SCANCODE_0;

	this->equipGlueKey.isDefault = true;
	this->equipGlueKey.userKey.clear();
	this->equipGlueKey.userSDLKey = SDL_SCANCODE_0;
}

void ControllManager::saveControls() {
	SaveKeybindings kb;
	kb.toggleFPSKey = this->toggleFPSKey;
	kb.walkLeftKey = this->walkLeftKey;
	kb.walkRightKey = this->walkRightKey;
	kb.stopKey = this->stopKey;
	kb.jumpKey = this->jumpKey;
	kb.equipPortalKey = this->equipPortalKey;
	kb.equipThrusterKey = this->equipThrusterKey;
	kb.equipGlueKey = this->equipGlueKey;

	GameSettings::getInstance().saveGame.settings.cm = kb;
	GameSettings::getInstance().save();
}

bool ControllManager::validKey(SDL_Scancode key, std::string action) {
	bool valid = true;
	std::vector<SDL_Scancode> InvalidKeys;
	InvalidKeys.push_back(SDL_SCANCODE_ESCAPE);
	InvalidKeys.push_back(SDL_SCANCODE_GRAVE);

	if (action != "toggleFPS") {
		if (this->toggleFPSKey.isDefault)
			InvalidKeys.push_back(this->toggleFPSKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->toggleFPSKey.userSDLKey);
	} 
	else if (action != "walkLeft") {
		if (this->walkLeftKey.isDefault)
			InvalidKeys.push_back(this->walkLeftKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->walkLeftKey.userSDLKey);
	}
	else if (action != "walkRight") {
		if (this->walkRightKey.isDefault)
			InvalidKeys.push_back(this->walkRightKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->walkRightKey.userSDLKey);
	}
	else if (action != "stop") {
		if (this->stopKey.isDefault)
			InvalidKeys.push_back(this->stopKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->stopKey.userSDLKey);
	}
	else if (action != "jump") {
		if (this->jumpKey.isDefault)
			InvalidKeys.push_back(this->jumpKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->jumpKey.userSDLKey);
	}
	else if (action != "equipPortal") {
		if (this->equipPortalKey.isDefault)
			InvalidKeys.push_back(this->equipPortalKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->equipPortalKey.userSDLKey);
	}
	else if (action != "equipThruster") {
		if (this->equipThrusterKey.isDefault)
			InvalidKeys.push_back(this->equipThrusterKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->equipThrusterKey.userSDLKey);
	}
	else if (action != "equipGlue") {
		if (this->equipThrusterKey.isDefault)
			InvalidKeys.push_back(this->equipGlueKey.defaultSDLKey);
		else
			InvalidKeys.push_back(this->equipGlueKey.userSDLKey);
	}

	for (size_t i = 0; i < InvalidKeys.size(); i++) {
		SDL_Scancode key2 = InvalidKeys[i];
		if (key2 == key) {
			valid = false;
			break;
		}
	}

	return valid;
}

void ControllManager::initializeControls() {
	SaveKeybindings Controlls = GameSettings::getInstance().saveGame.settings.cm;
	if (GameSettings::getInstance().saveGame.settings.cm.toggleFPSKey.defaultKey != "") {
		this->toggleFPSKey = KeybindingData(Controlls.toggleFPSKey.defaultKey, Controlls.toggleFPSKey.userKey, Controlls.toggleFPSKey.defaultSDLKey, Controlls.toggleFPSKey.userSDLKey, Controlls.toggleFPSKey.isDefault);
		this->walkLeftKey = KeybindingData(Controlls.walkLeftKey.defaultKey, Controlls.walkLeftKey.userKey, Controlls.walkLeftKey.defaultSDLKey, Controlls.walkLeftKey.userSDLKey, Controlls.walkLeftKey.isDefault);
		this->walkRightKey = KeybindingData(Controlls.walkRightKey.defaultKey, Controlls.walkRightKey.userKey, Controlls.walkRightKey.defaultSDLKey, Controlls.walkRightKey.userSDLKey, Controlls.walkRightKey.isDefault);
		this->stopKey = KeybindingData(Controlls.stopKey.defaultKey, Controlls.stopKey.userKey, Controlls.stopKey.defaultSDLKey, Controlls.stopKey.userSDLKey, Controlls.stopKey.isDefault);
		this->jumpKey = KeybindingData(Controlls.jumpKey.defaultKey, Controlls.jumpKey.userKey, Controlls.jumpKey.defaultSDLKey, Controlls.jumpKey.userSDLKey, Controlls.jumpKey.isDefault);
		this->equipPortalKey = KeybindingData(Controlls.equipPortalKey.defaultKey, Controlls.equipPortalKey.userKey, Controlls.equipPortalKey.defaultSDLKey, Controlls.equipPortalKey.userSDLKey, Controlls.equipPortalKey.isDefault);
		this->equipThrusterKey = KeybindingData(Controlls.equipThrusterKey.defaultKey, Controlls.equipThrusterKey.userKey, Controlls.equipThrusterKey.defaultSDLKey, Controlls.equipThrusterKey.userSDLKey, Controlls.equipThrusterKey.isDefault);
		this->equipGlueKey = KeybindingData(Controlls.equipGlueKey.defaultKey, Controlls.equipGlueKey.userKey, Controlls.equipGlueKey.defaultSDLKey, Controlls.equipGlueKey.userSDLKey, Controlls.equipGlueKey.isDefault);
	}
	else if (GameSettings::getInstance().saveGame.settings.cm.toggleFPSKey.defaultKey == "") {
		this->toggleFPSKey = KeybindingData("F3", SDL_SCANCODE_F3);
		this->walkLeftKey = KeybindingData("A", SDL_SCANCODE_A);
		this->walkRightKey = KeybindingData("D", SDL_SCANCODE_D);
		this->stopKey = KeybindingData("S", SDL_SCANCODE_S);
		this->jumpKey = KeybindingData("SPACE", SDL_SCANCODE_SPACE);
		this->equipPortalKey = KeybindingData("1", SDL_SCANCODE_1);
		this->equipThrusterKey = KeybindingData("2", SDL_SCANCODE_2);
		this->equipGlueKey = KeybindingData("3", SDL_SCANCODE_3);
	}
}

void ControllManager::updateControl(std::string action, std::string userKey, SDL_Scancode userSDLKey) {
	if (!validKey(userSDLKey, action))
		return;

	if (action == "toggleFPS") {
		this->toggleFPSKey.isDefault = false;
		this->toggleFPSKey.userKey = userKey;
		this->toggleFPSKey.userSDLKey = userSDLKey;
	}
	else if (action == "walkLeft") {
		this->walkLeftKey.isDefault = false;
		this->walkLeftKey.userKey = userKey;
		this->walkLeftKey.userSDLKey = userSDLKey;
	}
	else if (action == "walkRight") {
		this->walkRightKey.isDefault = false;
		this->walkRightKey.userKey = userKey;
		this->walkRightKey.userSDLKey = userSDLKey;
	}
	else if (action == "stop") {
		this->stopKey.isDefault = false;
		this->stopKey.userKey = userKey;
		this->stopKey.userSDLKey = userSDLKey;
	}
	else if (action == "jump") {
		this->jumpKey.isDefault = false;
		this->jumpKey.userKey = userKey;
		this->jumpKey.userSDLKey = userSDLKey;
	}
	else if (action == "equipPortal") {
		this->equipPortalKey.isDefault = false;
		this->equipPortalKey.userKey = userKey;
		this->equipPortalKey.userSDLKey = userSDLKey;
	}
	else if (action == "equipThruster") {
		this->equipThrusterKey.isDefault = false;
		this->equipThrusterKey.userKey = userKey;
		this->equipThrusterKey.userSDLKey = userSDLKey;
	}
	else if (action == "equipGlue") {
		this->equipGlueKey.isDefault = false;
		this->equipGlueKey.userKey = userKey;
		this->equipGlueKey.userSDLKey = userSDLKey;
	}
}
